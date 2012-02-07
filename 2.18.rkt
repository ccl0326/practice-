(define (list-reverse l)
  (define (list-reverse1 nl l)
    (if (null? l)
        nl
        (list-reverse1 (append  (list (car l))
                                nl) 
                       (cdr l))))
  (list-reverse1 '() l))


(list-reverse (list 1 2 3 4 5))