(require 'ox-publish)
(require 'ox-ascii)

(defun org-gemini-publish-to-gemini (plist filename pub-dir)
  (let* ((base (file-name-base filename))
         (output (concat (file-name-as-directory pub-dir) base ".gmi"))
         (content
          (org-export-string-as
           (with-temp-buffer
             (insert-file-contents filename)
             (buffer-string))
           'ascii t)))

    (make-directory (file-name-directory output) t)

    (with-temp-file output
      (insert content))))

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
             :publishing-function 'org-html-publish-to-html)

       (list "subramanyaj.gemini"
             :recursive t
             :base-directory "./content"
             :publishing-directory "./gemini"
             :publishing-function 'org-gemini-publish-to-gemini)))

(setq org-html-validation-link nil
      org-html-head-include-scripts nil
      org-html-head-include-default-style nil
      org-html-head
      "<link rel=\"stylesheet\" href=\"/static/styles.css\" />
<link rel=\"icon\" type=\"image/svg+xml\" href=\"/static/favicon.svg\" />")

(org-publish-all t)

(message "Build complete!")
