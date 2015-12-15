
(cl:in-package :asdf)

(defsystem "waypoint_planning-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Coordinates" :depends-on ("_package_Coordinates"))
    (:file "_package_Coordinates" :depends-on ("_package"))
    (:file "Replan_Msg" :depends-on ("_package_Replan_Msg"))
    (:file "_package_Replan_Msg" :depends-on ("_package"))
  ))