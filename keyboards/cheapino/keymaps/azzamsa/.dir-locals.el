;; .dir-locals.el — disable apheleia-mode for this project
((nil . ((eval . (when (fboundp 'apheleia-mode)
                   (apheleia-mode -1))))))
