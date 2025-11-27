# Math_engine
This repository will contain an math engine to enforce my gained knowledge of c++ and transform this into skills. This project will also extend into my understanding of calculus, and be the prerequisite of a simplistic math editor.

### Phases of development:
1. Project Foundations / Design
2. Tokenizer
3. Parser and grammar
4. AST design
5. Evaluation Engine
6. Symbolic Differentiation
7. REPL Interface and Usability
8. Testing. cleaning
9. Extend


### File structure:
`graphsql
math-engine/
│
├─ include/                # Header files
│   ├─ token.h             # TokenType enum and Token struct
│   ├─ tokenizer.h         # Tokenizer class declaration
│   ├─ ast.h               # AST Node base class & derived classes
│   ├─ parser.h            # Parser class declaration
│   └─ evaluator.h         # Evaluator functions/class
│
├─ src/                    # Implementation files
│   ├─ tokenizer.cpp       # Tokenizer implementation
│   ├─ parser.cpp          # Parser implementation
│   ├─ ast.cpp             # AST Node methods (if needed)
│   └─ evaluator.cpp       # Evaluator implementation
│
├─ tests/                  # Unit tests (optional but recommended)
│   └─ tokenizer_test.cpp
│
├─ main.cpp                # Entry point; simple REPL or test code
├─ CMakeLists.txt          # If using CMake for building (optional)
└─ README.md               # GitHub project description

`

## Phase 1:
1. Define token list
2. define tokenization rules
3. define grammar
4. define recursive-descent parser structure


#### Token list

| Token Type      | Example(s)     | Notes                                     |
| --------------- | -------------- | ----------------------------------------- |
| **NUMBER**      | `3`, `12.5`    | All numeric literals                      |
| **VARIABLE**    | `x`, `y`       | Single-letter or multi-letter identifiers |
| **OP_PLUS**     | `+`            | Addition                                  |
| **OP_MINUS**    | `-`            | Subtraction                               |
| **OP_MUL**      | `*`            | Multiplication                            |
| **OP_DIV**      | `/`            | Division                                  |
| **OP_POW**      | `^`            | Exponentiation                            |
| **LPAREN**      | `(`            | Left parenthesis                          |
| **RPAREN**      | `)`            | Right parenthesis                         |
| **FUNCTION**    | `sin`, `cos`   | Any recognized function name              |
| **END**         | *none*         | Signal end of input                       |
| **UNKNOWN/ERR** | any other char | For error handling               |


#### Grammar:
expression → term { (+|-) term }
term       → factor { (*|/) factor }
factor     → unary { ^ unary }
unary      → (+|-) unary | primary
primary    → NUMBER | VARIABLE | FUNCTION ('expression ')' | '(' expression ')'

#### AST structure:
Node types and children direction:
  1. BinaryOpNode -> Left and right
  2. UnaryOpNode -> one child
  3. FunctionNode -> one child
  4. VariableNode -> leaf
  5. ConstantNode -> leaf

#### Blueprint:
  1. Input → sequence of characters
  2. Tokenizer → converts characters to tokens
  3. Parser → consumes tokens according to grammar, builds AST
  4. AST → used for evaluation & differentiation

---
## Phase 2:

### Tokenizer
  - Input: Raw data.
  - Output: Vector of tokens
#### Goal:
  Accepts raw input data and tokenize it into a vector containing ordered indivual tokens.

1. Defined tokens in token.h
2. Tokenizer class interface and implementation in tokenizer.cpp/h

---
#### Parser
Recursive Descent Parser
  - Input: Vector of tokens
  - Output: AST
#### Goal:
Accepts Tokens and construct Abstract Syntax Tree (will be refered to as AST) and encodes operator precedence and grouping of expressions for simplified evaluation or transformation.

#### Purpose:
  - Rendering of visuals
  - Evaluate expressions
  - do symbolic manipulation
  - Posibble symbolic manipulation
  - Export


#### Roadmap:
  Stage 1: Basic arithmetic
  Stage 2: Exponents
  Stage 3: Functions
  Stage 4: Pretty Printing
  Stage 5: Advance Math constructs

