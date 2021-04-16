typedef struct ExprBlock * Expr;
typedef ListPair<Expr> ExprPair;
typedef ExprPair * ExprList;

// 2.Look at the provided code below

// The root of the Expression tree hierarchy
struct ExprBlock
{
    Type type;

    ExprBlock(Type ty)
        : type(ty)
    {
    }

    virtual void put(ostream & out)
    {
        compiler_error("Undefined member function: ExprBlock :: put");
    }

    virtual bool isConst()
    {
        return false;
    }

    virtual bool isLocation()
    {
        return false;
    }


};



struct BinaryExpr
    : ExprBlock
{
    Expr first;
    Expr second;
    BinaryExpr(Expr f, Expr s, Type ty = 0)
        : ExprBlock(ty), first(f), second(s)
    {
    }

    static Expr make(Expr f, Expr s)
    {
        return new BinaryExpr(f, s);
    }

};


/* a) Define "ArithmeticExpr" struct that inherits from BinaryExpr.
* Write a constructor that takes three parameters.
* The first 2 parameters are a type of "Expr", and the last one is a type of "Type" and has a default value of 0.
*/
struct ArithmeticExpr
    : ...


/* b) Define "PlusExpr" which is a type of ArithmeticExpr.
 * The constructor takes 2 expressions, and a "Type" with a default value set to 0.
 * Also, define a static function "make" which takes 2 expressions and returns a new PlusExpr.
 * Lastly, define a put function that prints the left and right operands of addition.
 *  e.g. 2 + 3
 */


/* c) Similar to PlusExpr, define MinusExpr.
 * Define, "constructor", "make", and "put" functions.
 */

