(require 'ox-publish)

;; Define
(setq org-publish-project-alist
      (list
       (list "subramanyaj.github.io"

             :with-author t
			 :author "Subramanya J"
			 :with-email t
			 :email "subramanyajaradhya [AT] gmail [DOT] com"

             :with-creator t
             :with-date t
             :time-stamp-file t

             :with-toc nil
             :section-numbers nil

             :recursive t
             :base-directory "./content"
             :publishing-directory "./docs"
             :publishing-function 'org-html-publish-to-html)))

(setq org-html-validation-link nil            
      org-html-head-include-scripts nil      
      org-html-head-include-default-style nil 
      org-html-head "<link rel=\"stylesheet\" href=\"/static/styles.css\" />
<link rel=\"icon\" type=\"image/svg+xml\" href=\"/static/favicon.svg\" />")

;; Generate
(org-publish-all t)

(message "Build complete!")
