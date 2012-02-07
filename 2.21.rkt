(define (square-list items)
  (if (null? items)
      '()
      (cons(* (car items) (car items)) (square-list (cdr items)))))

(define (square-list1 items)
  (map (lambda (x) (* x x)) items))



(square-list (list 1 2 3 4))
(square-list1 (list 1 2 3 4))