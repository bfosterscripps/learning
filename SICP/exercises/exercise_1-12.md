se 1.12. 
====

The following pattern of numbers is called Pascal's triangle.

The numbers at the edge of the triangle are all 1, and each number inside the triangle is the sum of the two numbers above it. 

Write a procedure that computes elements of Pascal's triangle by means of a recursive process.

I was beating myself up over this because I thought the requirement was to create a procedure that took one number and generated all of the other numbers for the triangle with a recursive process.

Looking up the answer after many variations of the answer on my end, I found I had the answer they wanted a long time ago:

(define (p r c)
    (cond ((= r 0) 1)
        ((= c 0) 1)
        ((= r c) 1)
        (else (+ (p (- r 1) c) (p (- r 1) (- c 1))))
    )
)
