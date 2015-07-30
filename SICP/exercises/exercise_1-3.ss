;;;; SICP Exercise 1.3:
;;;; Define a procedure that takes three numbers as arguments and
;;;; returns the sum of the squares of the two larger numbers.


(define (square x) (* x x))

(define (max x y z)
    (if (and (> x y) (> x z))
        x
        (if (> y z)
            y
            z
        )
    )
)

(define (second-highest x y z)
    (if (= (max x y z) x)
        (if (> y z)
            y
            z)
        (if (or (> x y) (> x z))
            x
            (if (> y z)
                z
                y)
        )
    )
)

(define (proc x y z)
    (+ (square (max x y z)) (square (second-highest x y z)))
)

(proc 3 5 2)
