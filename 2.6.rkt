(define f ((lambda (u) u) 5))


(define zero (lambda (f) (lambda (x) x)))

(define (add-1 n)
  (lambda (f) (lambda (x) (f ((n f) x)))))

(define one (lambda (f) (lambda (x) (f x))))

(define two (lambda (f) (lambda (x) (f (f x)))))

(define (add n1 n2)
  (lambda (f) (lambda(x) ((n1 f) ((n2 f) x )))))




(define (cn-to-n cn) ((cn (lambda (i) (+ i 1))) 0))


(cn-to-n two)