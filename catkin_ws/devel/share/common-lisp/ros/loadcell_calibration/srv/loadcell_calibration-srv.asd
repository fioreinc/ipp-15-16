
(cl:in-package :asdf)

(defsystem "loadcell_calibration-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "GetFactor" :depends-on ("_package_GetFactor"))
    (:file "_package_GetFactor" :depends-on ("_package"))
  ))