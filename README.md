Infix to Postfix Conversion — Algorithm Explanation

This document describes the algorithm used to convert a mathematical expression from infix notation (e.g., A + B * C) to postfix notation (Reverse Polish Notation, e.g., A B C * +).
The implementation uses a stack to correctly handle operator precedence and parentheses.

📘 1. Overview

Infix expressions are written in the form:

operand operator operand  
e.g., A + B


Postfix expressions place the operator after its operands:

operand operand operator  
e.g., A B +


Postfix notation has a major advantage:
➡️ It can be evaluated easily without parentheses or precedence rules.

This algorithm ensures correct postfix conversion by using a stack to temporarily store operators.

⚙️ 2. Operator Precedence

The algorithm uses the following precedence table:

Operator	Precedence
^	3 (highest)
*, /	2
+, -	1
Others	0

Higher value = higher priority during comparison.

🧠 3. How the Algorithm Works

The algorithm scans the infix expression from left to right and uses different actions depending on the current character.

Step-by-Step Rules
1. If the character is an operand (letter or digit):

➡️ Append it directly to the output.
Example:
A, b, 3, x → added to postfix result.

2. If the character is an opening parenthesis (:

➡️ Push it onto the operator stack.

We use this to delay pushing operators until we find its matching ).

3. If the character is a closing parenthesis ):

➡️ Pop operators from the stack and append them to output
until an opening parenthesis ( is found.

Finally, pop and discard the (.

4. If the character is an operator (+, -, *, /, ^):

We compare it with the operator at the top of the stack.

➡️ While the stack is not empty
and the precedence of the current operator is less than or equal to
the precedence of the operator on the top of the stack,
pop from the stack and append to output.

After popping, push the current operator onto the stack.

This ensures operators are arranged based on precedence and associativity.

5. After processing the entire expression

If operators remain in the stack:

➡️ Pop all remaining operators and append them to the postfix output.

No parentheses should remain at this stage.

📌 Example Walk-through

Consider:

(3 + 2) + 7 / 2 * ((7 + 3) * 2)


After processing the expression following the above rules, the final postfix output becomes:

32+72/73+2* *+

🧩 6. Why This Algorithm Works

Parentheses ensure strict grouping.

Operators are popped from the stack only when their precedence requires it.

The stack preserves the evaluation order without directly evaluating the expression.

Postfix expressions eliminate ambiguity and require no parentheses.

🚀 7. Summary

This algorithm:

✔ Correctly handles operator precedence
✔ Correctly processes nested parentheses
✔ Produces valid postfix expressions
✔ Works in O(n) time (each character processed once)

The result can be used immediately by postfix evaluation algorithms or expression calculators.
