/* 
When programming in C, it is sometimes necessary to make different
structs point to one another in acircular fashion. For example,
make a component of struct type A point to struct type B, and 
vice versa. The most obvious way of doing this involves references
to undefined structs, and will confuse many compilers. A solution to
this problem is to typedef the interlocking structs to aliases, then
use aliases to describe the references. For example,
*/

/* attach aliases to struct types */
typedef struct aa aa_type;
typedef struct bb bb_type;

/* use aliases in struct definition */
struct aa { bb_type *bb_pointer; };
struct bb { aa_type *aa_pointer; };

/* Structs aa and bb can also contain other components. */
