; Auto-generated. Do not edit!


(cl:in-package waypoint_planning-msg)


;//! \htmlinclude Replan_Msg.msg.html

(cl:defclass <Replan_Msg> (roslisp-msg-protocol:ros-message)
  ((uav_id
    :reader uav_id
    :initarg :uav_id
    :type cl:fixnum
    :initform 0)
   (coordinates
    :reader coordinates
    :initarg :coordinates
    :type waypoint_planning-msg:Coordinates
    :initform (cl:make-instance 'waypoint_planning-msg:Coordinates)))
)

(cl:defclass Replan_Msg (<Replan_Msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Replan_Msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Replan_Msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name waypoint_planning-msg:<Replan_Msg> is deprecated: use waypoint_planning-msg:Replan_Msg instead.")))

(cl:ensure-generic-function 'uav_id-val :lambda-list '(m))
(cl:defmethod uav_id-val ((m <Replan_Msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader waypoint_planning-msg:uav_id-val is deprecated.  Use waypoint_planning-msg:uav_id instead.")
  (uav_id m))

(cl:ensure-generic-function 'coordinates-val :lambda-list '(m))
(cl:defmethod coordinates-val ((m <Replan_Msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader waypoint_planning-msg:coordinates-val is deprecated.  Use waypoint_planning-msg:coordinates instead.")
  (coordinates m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Replan_Msg>) ostream)
  "Serializes a message object of type '<Replan_Msg>"
  (cl:let* ((signed (cl:slot-value msg 'uav_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'coordinates) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Replan_Msg>) istream)
  "Deserializes a message object of type '<Replan_Msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'uav_id) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'coordinates) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Replan_Msg>)))
  "Returns string type for a message object of type '<Replan_Msg>"
  "waypoint_planning/Replan_Msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Replan_Msg)))
  "Returns string type for a message object of type 'Replan_Msg"
  "waypoint_planning/Replan_Msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Replan_Msg>)))
  "Returns md5sum for a message object of type '<Replan_Msg>"
  "ba579b4b1534fcbd7ed9e29ed0638bff")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Replan_Msg)))
  "Returns md5sum for a message object of type 'Replan_Msg"
  "ba579b4b1534fcbd7ed9e29ed0638bff")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Replan_Msg>)))
  "Returns full string definition for message of type '<Replan_Msg>"
  (cl:format cl:nil "int8 uav_id~%waypoint_planning/Coordinates coordinates~%================================================================================~%MSG: waypoint_planning/Coordinates~%float64 longitude~%float64 latitude~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Replan_Msg)))
  "Returns full string definition for message of type 'Replan_Msg"
  (cl:format cl:nil "int8 uav_id~%waypoint_planning/Coordinates coordinates~%================================================================================~%MSG: waypoint_planning/Coordinates~%float64 longitude~%float64 latitude~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Replan_Msg>))
  (cl:+ 0
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'coordinates))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Replan_Msg>))
  "Converts a ROS message object to a list"
  (cl:list 'Replan_Msg
    (cl:cons ':uav_id (uav_id msg))
    (cl:cons ':coordinates (coordinates msg))
))
