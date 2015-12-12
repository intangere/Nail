##########################
#        Nail Lang       #
#  Reactive Programming  #
#       By Photonic      #
##########################
import strutils
import tables
import macros

#Declare the variables
var Container = initTable[string, string]()
var Dependencies = initTable[string, seq[string]]()
var AST: seq[seq[string]] = @[]
var order = ["BIND", "DEPENDS", "DIV", "MUL", "ADD", "SUB", "EQUAL", "ECHO", "CALL"]
var operators = ["EQUAL", "BIND", "DEPENDS", "DIV", "MUL", "ADD", "SUB", "ECHO", "CALL"]
var AST_NODES = initTable[string, seq[string]]()
var AST_FUNCTIONS = initTable[string, seq[seq[string]]]()
proc tokenize(program: string, stmt_type: string, func_name: string) = 
  echo program
  var tokens = program.split(" ")
  var q = 0
  while q < len(tokens):
    tokens[q] = strip(tokens[q])
    tokens[q] = tokens[q].replace(" ", "")
    if len(tokens[q]) == 0:
      system.delete(tokens, q)
    q += 1
  var t = 0
  var AST_NODE: seq[string] = @[]
  for token in tokens:
      if token.endswith("()"):
        if AST_FUNCTIONS.haskey(token[0.. -3]):
          add(AST, AST_FUNCTIONS[token[0.. -3]])
        else:
          quit("Error: $# is not defined." % [token[0.. -3]])
      else:
        case token:
          of ":=" :
            add(AST_NODE, "DEPENDS")
            var deps = tokens
            var i = 0
            while i < len(deps):
              case deps[i]:
                of "+", "-", "*", "/", "=", " ", ":=": 
                  deps.delete(i)
                  i -= 1
              i += 1
            deps.delete(0)
            add(AST_NODE, deps)
            add(AST_NODE, "BIND")
            add(AST_NODE, "EQUAL")
          of "fn" : discard
          of "+" : add(AST_NODE, "ADD")
          of "-" : add(AST_NODE, "SUB")
          of "*" : add(AST_NODE, "MUL")
          of "/" : add(AST_NODE, "DIV")
          of "=" : add(AST_NODE, "EQUAL")
          of "echo" : add(AST_NODE, "ECHO")
          of " " : discard token
          of "" : discard token
          else : add(AST_NODE, token)
      t += 1
  echo "AST_NODE", AST_NODE
  if len(AST_NODE) > 0:
    if stmt_type == "AST":
      add(AST, AST_NODE)
    elif stmt_type == "FUNC":
        AST_FUNCTIONS.mget(func_name).add(AST_NODE)
proc interpret*() = 
    var x = 0
    while x < len(AST):
      for value in order:
        var i = 0
        var node = AST[x]
        while i < len(node):
            var expr = node[i]
            if expr == value:
                if expr in operators:
                  var expr1 = ""
                  var expr2 = ""
                  try:
                    expr1 = node[i-1]
                    if Container.haskey(expr1):
                      expr1 = Container[expr1]
                  except IndexError:
                    discard
                  try:
                    expr2 = node[i+1]
                    if Container.haskey(expr2):
                      expr2 = Container[expr2]
                  except IndexError:
                    discard
                  if expr == "EQUAL":
                    for key, values in Dependencies: #WORK ON THIS!
                      var ast_node: seq[string] = @[]
                      if values.contains(node[i-1]):
                        add(ast_node, key)
                        add(ast_node, "EQUAL")
                        for expr in AST_NODES[key]:
                          add(ast_node, expr)
                        AST.insert(ast_node, x+1)
                    Container[node[i-1]] = expr2
                    node[i+1] = expr2
                    system.delete(node, i+1)
                    system.delete(node, i)
                    system.delete(node, i-1)             
                    i -= 1
                  if expr == "DIV":
                    node[i] = formatFloat(parseInt(expr1) / parseInt(expr2))
                    system.delete(node, i+1)
                    system.delete(node, i-1)         
                    i -= 2
                  if expr == "MUL":
                    node[i] = formatFloat(parseFloat(expr1) * parseFloat(expr2))
                    system.delete(node, i+1)
                    system.delete(node, i-1)                              
                    i -= 2
                  if expr == "ADD":
                    node[i] = formatFloat(parseFloat(expr1) + parseFloat(expr2))
                    system.delete(node, i+1)
                    system.delete(node, i-1)
                    i -= 2
                  if expr == "SUB":
                    node[i] = formatFloat(parseFloat(expr1) - parseFloat(expr2))
                    system.delete(node, i+1)
                    system.delete(node, i-1)       
                    i -= 2
                  if expr == "DEPENDS":
                    var c = i
                    system.delete(node, c)
                    while node[c] != "BIND":
                      var dep = node[c]
                      if Dependencies.haskey(expr1):
                        if not Dependencies[expr1].contains(dep):
                          Dependencies.mget(expr1).add(dep)
                      else:
                        Dependencies[expr1] = @[]
                        Dependencies.mget(expr1).add(dep)
                      system.delete(node, c)
                    system.delete(node, c)
                  if expr == "BIND":
                    var b = i+2
                    while b < len(node):
                      if AST_NODES.has_key(node[0]):
                        AST_NODES.mget(node[0]).add(node[b])
                      else:
                        AST_NODES[node[0]] = @[]
                        AST_NODES.mget(node[0]).add(node[b])
                      b+=1  
                  if expr == "ECHO":
                    echo expr2
                    system.delete(node, i+1)
                    system.delete(node, i)
                  AST[x] = node
            i = i + 1
      if len(AST[x]) == 0:
        system.delete(AST, x)
     # echo "REAL",AST

proc Reactive(r: string, value: string) = 
  if Container.hasKey(r):
    Container.mget(r).add(r)
  else:
    Container[r] = ""
    Container.mget(r).add(r)

when isMainModule:
  import os
  var program = if paramCount() > 0: readFile paramStr(1)
    else: readAll stdin
  var lines = program.split("\n")
  var functions: seq[string] = @[]
  var current_ident = 0
  var func_name = ""
  var q = 0
  var insert_at_line = 0
  while q < len(lines):
    if lines[q].startswith("fn "):
      func_name = lines[q].split("fn ")[1].split(":")[0].strip()
      if AST_FUNCTIONS.has_key(func_name):
        discard
      else:
        AST_FUNCTIONS[func_name] = @[]
      insert_at_line = q
      system.delete(lines, q)
    elif lines[q].startswith(" "):
      var i = 0
      while lines[q][i] == ' ':
        i += 1
      if current_ident == 0:
        current_ident = i
        tokenize(strip(lines[q]), "FUNC", func_name)
        system.delete(lines, q)
      elif (current_ident == i) or (i > current_ident):
        tokenize(strip(lines[q]), "FUNC", func_name)
        system.delete(lines, q)
      else:
        #We have gone out of the scope
        current_ident = 0
    else:
      q += 1
  var a = 0

  for line in lines:
    tokenize(line, "AST", "")

  #for KEY, NODE in AST_FUNCTIONS:
  #  AST.insert(NODE, 0)
  echo "AST FUNCTIONS ", AST_FUNCTIONS
  echo "AST TREE", AST
  interpret()
    #for line in program.split("\n"):
    #  tokenize line


#type 
#    R = ref object of Reactive
#      name*: self
#      value*: string
#  while i < len(lines):
#   if ("fn " in lines[i]) and ("{" in lines[i]):
#      var t = i
#      echo lines[i]
#      while "}" notin lines[t]:
#        echo lines[t]
#        lines[i].add(lines[t])
#        system.delete(lines, t)
#    i += 1
#  echo lines

#  var t = 0
#  var i = 0
#  while i < len(program):
#    if program[i] == '{':
#      t = i
#      while program[t] != '}':
#        function.add(program)
#        program.delete(t, t)
#        echo program
#    i += 1
#  echo program
#Braces implementation