Exercise 1.10. 
=====
The following procedure computes a mathematical function called Ackermann's function.
```
(define (A x y)
  (cond ((= y 0) 0)
        ((= x 0) (* 2 y))
        ((= y 1) 2)
        (else (A (- x 1)
                 (A x (- y 1))))))
```

What are the values of the following expressions?
`(A 1 10)`
`(A 2 4)`
`(A 3 3)`


Consider the following procedures, where A is the procedure defined above:
`(define (f n) (A 0 n))`
`(define (g n) (A 1 n))`
`(define (h n) (A 2 n))`



Give concise mathematical definitions for the functions computed by the procedures f, g, and h for positive integer values of n. For example, 
`(define (k n) (* 5 n n))`, `(k n)` computes `5n^2`.

-----

What are the values of the following expressions?
------
- `(A 1 10)`

this is equivalent to 2^10 = 1024

- `(A 2 4)`

this is equivalent to 2^2^2^2, (2^16) = 65536

- `(A 3 3)`

this is the same as `(A 2 4)` - it turns into 2^16 after expansion and iteration - which is 65536

----
----
Give concise mathematical definitions for the functions computed by the procedures f, g, and h for positive integer values of n.
-----

- `(define (f n) (A 0 n))`

this is equivalent to 2n

- `(define (g n) (A 1 n))`

this is equivalent to 2^n

- `(define (h n) (A 2 n))`

this is equivalent to 2^2^... (n times)
e.g. `(A 2 4)` is 2^2^2^2 and `(A 2 3)` is 2^2^2


Checked my answers against this: http://community.schemewiki.org/?sicp-ex-1.10
Looks right to me.
This one was quite an issue - especially figuring out notation for `(A 2 n)` - which had me coming up with notation after notation - falsifying each.
The answer was so simple and obvious to me once I had a moment to think unrestrained by noise and bustling outside.
