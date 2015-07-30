Alyssa P. Hacker doesn't see why _if_ needs to be provided as a special form. ``Why can't I just define it as an ordinary procedure in terms of cond?'' she asks. Alyssa's friend Eva Lu Ator claims this can indeed be done, and she defines a new version of if:

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
        (else else-clause)))


Eva demonstrates the program for Alyssa:
(new-if (= 2 3) 0 5)
5
(new-if (= 1 1) 0 5)
0


Delighted, Alyssa uses new-if to rewrite the square-root program:

(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
          guess
          (sqrt-iter (improve guess x)
                    x)))

What happens when Alyssa attempts to use this to compute square roots? Explain.


--------

The answer has to do with applicative order: https://en.wikipedia.org/wiki/Evaluation_strategy#Applicative_order
If is a special form for a reason: so that based on a condition one clause may run and not the other.
Scheme functions don't work this way - and with her new-if function, both the then-clause and the else-clause have to be executed and returned before the main function finishes.
So in the case of her sqrt-iter function - her else-clause endlessly recurses because at no point does the new-if run the then-clause and not the else clause.
It's an infinite loop.
