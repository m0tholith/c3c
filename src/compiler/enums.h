// Copyright (c) 2019 Christoffer Lerno. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// Only include this from compiler_common.h

typedef enum
{
	ASSIGNOP_ERROR,
	ASSIGNOP_ASSIGN,
	ASSIGNOP_MULT_ASSIGN,
	ASSIGNOP_ADD_ASSIGN,
	ASSIGNOP_SUB_ASSIGN,
	ASSIGNOP_DIV_ASSIGN,
	ASSIGNOP_MOD_ASSIGN,
	ASSIGNOP_AND_ASSIGN,
	ASSIGNOP_OR_ASSIGN,
	ASSIGNOP_BIT_AND_ASSIGN,
	ASSIGNOP_BIT_OR_ASSIGN,
	ASSIGNOP_BIT_XOR_ASSIGN,
	ASSIGNOP_SHR_ASSIGN,
	ASSIGNOP_SHL_ASSIGN,
} AssignOp;

typedef enum
{
	BINARYOP_ERROR,
	BINARYOP_MULT,
	BINARYOP_SUB,
	BINARYOP_ADD,
	BINARYOP_DIV,
	BINARYOP_MOD,
	BINARYOP_SHR,
	BINARYOP_SHL,
	BINARYOP_BIT_OR,
	BINARYOP_BIT_XOR,
	BINARYOP_BIT_AND,
	BINARYOP_AND,
	BINARYOP_OR,
	BINARYOP_GT,
	BINARYOP_GE,
	BINARYOP_LT,
	BINARYOP_LE,
	BINARYOP_NE,
	BINARYOP_EQ,
	// Only "assign" BINOPS after this point
	BINARYOP_ASSIGN,
	BINARYOP_MULT_ASSIGN,
	BINARYOP_ADD_ASSIGN,
	BINARYOP_SUB_ASSIGN,
	BINARYOP_DIV_ASSIGN,
	BINARYOP_MOD_ASSIGN,
	BINARYOP_AND_ASSIGN,
	BINARYOP_OR_ASSIGN,
	BINARYOP_BIT_AND_ASSIGN,
	BINARYOP_BIT_OR_ASSIGN,
	BINARYOP_BIT_XOR_ASSIGN,
	BINARYOP_SHR_ASSIGN,
	BINARYOP_SHL_ASSIGN,
} BinaryOp;

typedef enum
{
	AST_POISONED,
	AST_ASM_STMT,
	AST_ATTRIBUTE,
	AST_BREAK_STMT,
	AST_CASE_STMT,
	AST_CATCH_STMT,
	AST_COMPOUND_STMT,
	AST_COND_STMT,
	AST_CONTINUE_STMT,
	AST_CT_IF_STMT,
	AST_CT_ELIF_STMT,
	AST_CT_ELSE_STMT,
	AST_CT_FOR_STMT,
	AST_CT_SWITCH_STMT,
	AST_CT_DEFAULT_STMT,
	AST_CT_CASE_STMT,
	AST_DECLARE_STMT,
	AST_DEFAULT_STMT,
	AST_DEFER_STMT,
	AST_DO_STMT,
	AST_EXPR_STMT,
	AST_FOR_STMT,
	AST_GENERIC_CASE_STMT,
	AST_GENERIC_DEFAULT_STMT,
	AST_GOTO_STMT,
	AST_IF_STMT,
	AST_LABEL,
	AST_NOP_STMT,
	AST_RETURN_STMT,
	AST_STMT_LIST,
	AST_SWITCH_STMT,
	AST_THROW_STMT,
	AST_TRY_STMT,
	AST_NEXT_STMT,
	AST_VOLATILE_STMT,
	AST_WHILE_STMT,
} AstKind;

typedef enum
{
	ATTR_INVALID,
	ATTR_UNRESOLVED,
} AttrKind;

typedef enum
{
	CASE_VALUE_INT,
	CASE_VALUE_UINT,
	CASE_VALUE_DEFAULT
} CaseValueType;

typedef enum
{
	CAST_ERROR,
	CAST_PTRPTR,
	CAST_PTRXI,
	CAST_VARRPTR,
	CAST_ARRPTR,
	CAST_STRPTR,
	CAST_PTRBOOL,
	CAST_BOOLINT,
	CAST_BOOLFP,
	CAST_FPBOOL,
	CAST_INTBOOL,
	CAST_FPFP,
	CAST_FPSI,
	CAST_FPUI,
	CAST_SISI,
	CAST_SIUI,
	CAST_SIFP,
	CAST_XIPTR,
	CAST_UISI,
	CAST_UIUI,
	CAST_UIFP,
	CAST_ENUMSI,
	/*
	CAST_NONE,
	CAST_INLINE,
	CAST_FAILED,
	CAST_SUBTYPE,
	CAST_VARRPTR,
	CAST_STRPTR,
	CAST_ARRPTR,
	CAST_INTPTR,
	CAST_PTRINT,
	CAST_PTRBOOL,
	CAST_FPFP,
	CAST_FPUI,
	CAST_FPSI,
	CAST_FPBOOL,
	CAST_UIFP,
	CAST_UIUI,
	CAST_UISI,
	CAST_SIFP,
	CAST_SISI,
	CAST_SIUI,
	CAST_INTBOOL,
	CAST_BOOLFP,
	CAST_BOOLINT,
	CAST_RVALUE,*/
} CastKind;

typedef enum _CastType
{
	CAST_TYPE_EXPLICIT,
	CAST_TYPE_IMPLICIT,
	CAST_TYPE_IMPLICIT_ASSIGN,
	CAST_TYPE_IMPLICIT_ASSIGN_ADD,
} CastType;

typedef enum
{
	CONST_NIL,
	CONST_BOOL,
	CONST_INT,
	CONST_FLOAT,
	CONST_STRING,
} ConstType;


typedef enum
{
	DECL_POISONED = 0,
	DECL_FUNC,
	DECL_VAR,
	DECL_ENUM_CONSTANT,
	DECL_TYPEDEF,
	DECL_STRUCT,
	DECL_UNION,
	DECL_ENUM,
	DECL_ERROR,
	DECL_ERROR_CONSTANT,
	DECL_ARRAY_VALUE,
	DECL_IMPORT,
	DECL_MACRO,
	DECL_MULTI_DECL,
	DECL_GENERIC,
	DECL_CT_IF,
	DECL_CT_ELSE,
	DECL_CT_ELIF,
	DECL_ATTRIBUTE,
} DeclKind;

// Ordering here is in priority if two branches should have the same exit.
typedef enum
{
	EXIT_NONE,
	EXIT_BREAK,
	EXIT_GOTO,
	EXIT_CONTINUE,
	EXIT_RETURN,
} ExitType;

typedef enum
{
	EXPR_POISONED,
	EXPR_TRY,
	EXPR_CONST,
	EXPR_BINARY,
	EXPR_CONDITIONAL,
	EXPR_UNARY,
	EXPR_POST_UNARY,
	EXPR_TYPE,
	EXPR_IDENTIFIER,
	EXPR_TYPE_ACCESS,
	EXPR_CALL,
	EXPR_SIZEOF,
	EXPR_SUBSCRIPT,
	EXPR_ACCESS,
	EXPR_STRUCT_VALUE,
	EXPR_STRUCT_INIT_VALUES,
	EXPR_INITIALIZER_LIST,
	EXPR_EXPRESSION_LIST,
	EXPR_CAST,
} ExprKind;

typedef enum
{
	GOTO_NOT_ANALYSED,
	GOTO_JUMP_FORWARD,
	GOTO_JUMP_BACK
} GotoType;

typedef enum
{
	IMPORT_TYPE_FULL,
	IMPORT_TYPE_ALIAS,
	IMPORT_TYPE_ALIAS_LOCAL,
	IMPORT_TYPE_LOCAL
} ImportType;


typedef enum
{
	LEXER_STATE_NORMAL,
	LEXER_STATE_DOCS_PARSE,
	LEXER_STATE_DOCS_PARSE_DIRECTIVE,
} LexerState;

typedef enum
{
	NUMBER_TYPE_BOOL,
	NUMBER_TYPE_FLOAT,
	NUMBER_TYPE_SIGNED_INT,
	NUMBER_TYPE_UNSIGNED_INT,
} NumberType;

typedef enum
{
	PREC_NONE,
	PREC_ASSIGNMENT,        // =, *=, /=, %=, ...
	PREC_CONDITIONAL,       // ?:
	PREC_LOGICAL,           // && ||
	PREC_RELATIONAL,        // < > <= >= == !=
	PREC_ADDITIVE,          // + -
	PREC_BIT,               // ^ | &
	PREC_SHIFT,             // << >> >>>
	PREC_MULTIPLICATIVE,    // * / %
	PREC_UNARY,             // ! - + ~ * & prefix ++/--
	PREC_CALL,              // . () [] postfix ++/--
} Precedence;

typedef enum
{
	SCOPE_NONE = 0,
	SCOPE_BREAK = 1 << 0,
	SCOPE_CONTINUE = 1 << 1,
	SCOPE_CONTROL = 1 << 2,
	SCOPE_NEXT = 1 << 3,
	SCOPE_DEFER = 1 << 4,
} ScopeFlags;

typedef enum
{
	RESOLVE_NOT_DONE = 0,
	RESOLVE_RUNNING,
	RESOLVE_DONE
} ResolveStatus;

typedef enum
{
	TOKEN_INVALID_TOKEN = 0,

	// Single-character tokens.
	TOKEN_AMP,              // &
	TOKEN_AT,               // @
	TOKEN_BIT_NOT,          // ~
	TOKEN_BIT_OR,           // =
	TOKEN_BIT_XOR,          // ^
	TOKEN_COLON,            // :
	TOKEN_COMMA,            // ,
	TOKEN_EOS,              // ;
	TOKEN_EQ,               // =
	TOKEN_GREATER,          // >
	TOKEN_DIV,              // /
	TOKEN_DOLLAR,           // $
	TOKEN_DOT,              // .
	TOKEN_HASH,             // #
	TOKEN_LESS,             // <
	TOKEN_LBRACE,           // {
	TOKEN_LBRACKET,         // [
	TOKEN_LPAREN,           // (
	TOKEN_MINUS,            // -
	TOKEN_MOD,              // %
	TOKEN_NOT,              // !
	TOKEN_OR,               // |
	TOKEN_PLUS,             // +
	TOKEN_QUESTION,         // ?
	TOKEN_RBRACE,           // }
	TOKEN_RBRACKET,         // ]
	TOKEN_RPAREN,           // )
	TOKEN_STAR,             // *

	// two character tokens.
	TOKEN_AND,              // &&
	TOKEN_ARROW,            // -> // Not used but reserved
	TOKEN_BIT_AND_ASSIGN,   // &=
	TOKEN_BIT_OR_ASSIGN,    // |=
	TOKEN_BIT_XOR_ASSIGN,   // ^=
	TOKEN_DIV_ASSIGN,       // /=
	TOKEN_DOTDOT,           // ..
	TOKEN_ELVIS,            // ?:
	TOKEN_EQEQ,             // ==
	TOKEN_GREATER_EQ,       // >=
	TOKEN_LESS_EQ,          // <=
	TOKEN_LPARBRA,          // ({
	TOKEN_MINUS_ASSIGN,     // -=
	TOKEN_MINUSMINUS,       // --
	TOKEN_MOD_ASSIGN,       // %=
	TOKEN_MULT_ASSIGN,      // *=
	TOKEN_NOT_EQUAL,        // !=
	TOKEN_PLUS_ASSIGN,      // +=
	TOKEN_PLUSPLUS,         // ++
	TOKEN_RPARBRA,          // })
	TOKEN_SCOPE,            // ::
	TOKEN_SHR,              // >>
	TOKEN_SHL,              // >>

	// Three or more
	TOKEN_AND_ASSIGN,       // &&=
	TOKEN_ELIPSIS,          // ...
	TOKEN_OR_ASSIGN,        // ||=
	TOKEN_SHR_ASSIGN,       // >>=
	TOKEN_SHL_ASSIGN,       // >>=

	// Basic types names
	TOKEN_VOID,
	TOKEN_BYTE,
	TOKEN_BOOL,
	TOKEN_CHAR,
	TOKEN_DOUBLE,
	TOKEN_FLOAT,
	TOKEN_HALF,
	TOKEN_INT,
	TOKEN_ISIZE,
	TOKEN_LONG,
	TOKEN_SHORT,
	TOKEN_UINT,
	TOKEN_ULONG,
	TOKEN_USHORT,
	TOKEN_USIZE,
	TOKEN_QUAD,

	// C types
	TOKEN_C_SHORT,
	TOKEN_C_INT,
	TOKEN_C_LONG,
	TOKEN_C_LONGLONG,
	TOKEN_C_USHORT,
	TOKEN_C_UINT,
	TOKEN_C_ULONG,
	TOKEN_C_ULONGLONG,


	// Literals.

	TOKEN_IDENT,            // Any normal ident.
	TOKEN_CONST_IDENT,      // Any purely upper case ident,
	TOKEN_TYPE_IDENT,       // Any ident on the format FooBar or __FooBar

	// We want to parse @foo / #foo / $foo separately.
	// Otherwise we allow things like "@ foo" which would be pretty bad.
	TOKEN_AT_IDENT,         // @foobar
	TOKEN_HASH_IDENT,       // #foobar
	TOKEN_CT_IDENT,     // $foobar

	TOKEN_STRING,           // "Teststring"
	TOKEN_INTEGER,          // 123 0x23 0b10010 0o327
	TOKEN_REAL,             // 0x23.2p-2a 43.23e23

	// Keywords
	TOKEN_ALIAS,            // Reserved
	TOKEN_AS,
	TOKEN_ASM,
	TOKEN_ATTRIBUTE,
	TOKEN_BREAK,
	TOKEN_CASE,
	TOKEN_CAST,
	TOKEN_CATCH,
	TOKEN_CONST,
	TOKEN_CONTINUE,
	TOKEN_DEFAULT,
	TOKEN_DEFER,
	TOKEN_DO,
	TOKEN_ELSE,
	TOKEN_ENUM,
	TOKEN_ERROR_TYPE,
	TOKEN_FALSE,
	TOKEN_FOR,
	TOKEN_FUNC,
	TOKEN_GENERIC,
	TOKEN_GOTO,
	TOKEN_IF,
	TOKEN_IMPORT,
	TOKEN_IN,
	TOKEN_LOCAL,
	TOKEN_MACRO,
	TOKEN_MODULE,
	TOKEN_NEXT,
	TOKEN_NIL,
	TOKEN_PUBLIC,
	TOKEN_RETURN,
	TOKEN_STRUCT,
	TOKEN_SWITCH,
	TOKEN_THROW,
	TOKEN_THROWS,
	TOKEN_TRUE,
	TOKEN_TRY,
	TOKEN_TYPE,             // Reserved
	TOKEN_TYPEDEF,
	TOKEN_UNION,
	TOKEN_UNTIL,
	TOKEN_VAR,              // Reserved
	TOKEN_VOLATILE,
	TOKEN_WHILE,

	TOKEN_AT_PARAM,         // @param
	TOKEN_AT_THROWS,        // @throws
	TOKEN_AT_RETURN,        // @return
	TOKEN_AT_ENSURE,        // @ensure
	TOKEN_AT_REQUIRE,       // @require
	TOKEN_AT_PURE,          // @pure
	TOKEN_AT_CONST,         // @const
	TOKEN_AT_REQPARSE,      // @reqparse
	TOKEN_AT_DEPRECATED,    // @deprecated

	TOKEN_CT_CASE,          // $case
	TOKEN_CT_DEFAULT,       // $default
	TOKEN_CT_FOR,           // $for
	TOKEN_CT_ELIF,          // $elif
	TOKEN_CT_ELSE,          // $else
	TOKEN_CT_IF,            // $if
	TOKEN_CT_SWITCH,        // $switch

	TOKEN_DOCS_START,       // /**
	TOKEN_DOCS_END,         // */ (may start with an arbitrary number of `*`
	TOKEN_DOCS_EOL,         // "\n" only seen in docs.
	TOKEN_DOCS_LINE,        // Any line within /** **/

	TOKEN_EOF,              // \n - SHOULD ALWAYS BE THE LAST TOKEN.

} TokenType;


typedef enum
{
	TYPE_POISONED,
	TYPE_VOID,
	TYPE_BOOL,
	TYPE_I8,
	TYPE_I16,
	TYPE_I32,
	TYPE_I64,
	TYPE_IXX,
	TYPE_U8,
	TYPE_U16,
	TYPE_U32,
	TYPE_U64,
	TYPE_UXX,
	TYPE_F32,
	TYPE_F64,
	TYPE_FXX,
	TYPE_FUNC,
	TYPE_USER_DEFINED,
	TYPE_POINTER,
	TYPE_STRING,
	TYPE_ARRAY,
	TYPE_VARARRAY,
	TYPE_INC_ARRAY,
	TYPE_EXPRESSION,
} TypeKind;

typedef enum
{
	UNARYOP_ERROR,
	UNARYOP_DEREF,
	UNARYOP_ADDR,
	UNARYOP_NEG,
	UNARYOP_BITNEG,
	UNARYOP_NOT,
	UNARYOP_INC,
	UNARYOP_DEC,
} UnaryOp;

typedef enum
{
	VARDECL_CONST = 0,
	VARDECL_GLOBAL = 1,
	VARDECL_LOCAL = 2,
	VARDECL_PARAM = 3,
	VARDECL_MEMBER = 4,
} VarDeclKind;

typedef enum
{
	VISIBLE_MODULE,
	VISIBLE_LOCAL,
	VISIBLE_PUBLIC,
} Visibility;


typedef enum
{
	ATTR_FUNC = 1 << 0,
	ATTR_VAR = 1 << 1,
	ATTR_ENUM = 1 << 2,
	ATTR_STRUCT = 1 << 3,
	ATTR_UNION = 1 << 4,
	ATTR_CONST = 1 << 5,
	ATTR_ERROR = 1 << 6,
	ATTR_TYPEDEF = 1 << 7
} AttributeDomains;
