(define (_map function l)
  (define (__map l res)
    (if (null? l)
        res
        (__map  (cdr l) 
                (append res 
                        (list (function (car l)))))))
  (__map l '()))


(define (_reduce function l init)
  (define (__reduce l res)
    (if (null? l)
        res
        (__reduce (cdr l)
                  (function res 
                            (car l)))))
  (__reduce l init))


(define (testfun g)
  (+ g 1))

(define (testfun1 g x)
  (+ g x))

(_map testfun (list 1 2 3 4 5))
(_reduce testfun1 (_map testfun (list 1 2 3 4 5)) 0)

(define (same x y)
  (= 0 (remainder  (abs (- x y)) 2)))

(define (same-parity x . l)
  (define (to-same g)
    (if (same g x)
        (list g)
        '()))
  (define (make-list r g)
    (append r g))
  (_reduce make-list (_map to-same l) (list x)))

(same-parity 1 2 3 4 5 6 7)