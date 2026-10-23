# Postfix Notation

[Source code](../../../Algorithms/Postfix%20Notation.cpp) | [All Algorithms explanations](../README.md)

The program attempts to evaluate a space-separated postfix expression. Operators follow their operands: 8 2 / means 8 divided by 2. The supported operator tokens are +, -, *, /, %, and ^, with ^ implemented using pow.

The code tokenizes one line into arr, then repeatedly scans into arr2. When its scan sees two adjacent numeric tokens, it treats the next token as an operator, replaces those three tokens with their result, and starts another pass if a reduction occurred. When no more reductions occur, a second loop combines values using the variables a and b and writes intermediate results back into arr2.

For the simple input 8 2 /, the final loop computes 8 / 2 and prints 4.0. Results use float, pass through to_string and stof, and are printed with one digit after the decimal point. Remainder converts both operands to int before applying %.

This is not a general stack-based postfix evaluator. The reduction checks that the first two tokens are numeric but does not check that the third is an operator. For 1 2 3 * +, it consumes 1 2 3 as a group and leaves its default result zero. On the next pass it tries to parse * as a number and terminates with an uncaught stof exception instead of producing 7.0. Some scan branches also read arr[i + 1] without checking that it exists. A single numeric token can therefore cause an out-of-bounds access before the later single-result branch is reached.

Let T be the token count. For executions that stay in bounds, at most O(T) reduction passes scan O(T) tokens, giving O(T²) token-processing work and O(T) token slots of storage. Numeric parsing and string copying add costs proportional to the text processed. This is a structural bound, not a correctness guarantee for arbitrary expressions.

The code does not validate expression structure, division by zero, or a zero integer divisor for %. Negative numeric tokens such as -3 are accepted by stof because they do not equal the standalone subtraction operator.
