# 🔄 Infix to Prefix and Postfix Conversion

This project explains how to convert an **Infix Expression** (the normal mathematical way of writing equations) into **Prefix** and **Postfix** formats.

---

## 📌 What Are These Notations?

| **Type**   | **Definition** | **Example (A, B are operands)** |
|------------|----------------|---------------------------------|
| **Infix**  | Operator is **between operands** | `A + B` |
| **Prefix** | Operator is **before operands**  | `+ A B` |
| **Postfix**| Operator is **after operands**   | `A B +` |

👉 We humans prefer **Infix**, but computers find it harder to evaluate because they need to check **precedence (priority of operators)** and **parentheses**.  
👉 Prefix and Postfix remove this confusion, making evaluation faster and easier for machines.

---

## 🎯 Why Is Conversion Needed?

- **Infix** expressions (like `A + B * C`) require rules of **BODMAS/precedence**.  
- Computers work better with **Prefix** or **Postfix** because:
  - No parentheses are required
  - No precedence confusion
  - Evaluation is direct using stacks

Example:  
- Infix: `A + B * C`  
- Postfix: `A B C * +`  
- Prefix: `+ A * B C`

---

## 🛠 How Does the Conversion Work?

1. **For Infix → Postfix**  
   - Scan the infix expression from left to right.  
   - Operands (A, B, C…) are directly added to the result.  
   - Operators (+, -, *, /, ^) are pushed into a stack depending on **precedence**.  
   - If `(` appears, push into stack.  
   - If `)` appears, pop until `(` is found.  
   - At the end, pop all remaining operators.

   ✅ Example:  
   - Infix: `(A + B) * C`  
   - Postfix: `A B + C *`

---

2. **For Infix → Prefix**  
   - Reverse the infix expression.  
   - Swap `(` with `)` and vice versa.  
   - Apply the **Infix → Postfix** method.  
   - Finally, reverse the result.  

   ✅ Example:  
   - Infix: `(A + B) * C`  
   - Prefix: `* + A B C`

---

## 📂 Key Points to Remember

- **Precedence of Operators (Highest → Lowest):**
  1. `^` (Power)  
  2. `*`, `/` (Multiplication, Division)  
  3. `+`, `-` (Addition, Subtraction)

- **Associativity:**  
  - `^` is **Right to Left**  
  - `*`, `/`, `+`, `-` are **Left to Right**

---

## ✅ Example Conversions

| Infix Expression | Prefix       | Postfix     |
|------------------|-------------|-------------|
| `A + B`          | `+ A B`     | `A B +`     |
| `A + B * C`      | `+ A * B C` | `A B C * +` |
| `(A + B) * C`    | `* + A B C` | `A B + C *` |
| `A * (B + C)`    | `* A + B C` | `A B C + *` |

---

## 📖 In Simple Words

- **Infix** = what we write normally  
- **Prefix** = operator comes **before**  
- **Postfix** = operator comes **after**  

This program helps us **convert** from **Infix → Prefix** and **Infix → Postfix** so that **computers can evaluate expressions easily**.
