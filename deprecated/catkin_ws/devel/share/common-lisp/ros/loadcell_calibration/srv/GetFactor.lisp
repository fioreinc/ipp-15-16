; Auto-generated. Do not edit!


(cl:in-package loadcell_calibration-srv)


;//! \htmlinclude GetFactor-request.msg.html

(cl:defclass <GetFactor-request> (roslisp-msg-protocol:ros-message)
  ((lbs_reading
    :reader lbs_reading
    :initarg :lbs_reading
    :type cl:float
    :initform 0.0))
)

(cl:defclass GetFactor-request (<GetFactor-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetFactor-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetFactor-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name loadcell_calibration-srv:<GetFactor-request> is deprecated: use loadcell_calibration-srv:GetFactor-request instead.")))

(cl:ensure-generic-function 'lbs_reading-val :lambda-list '(m))
(cl:defmethod lbs_reading-val ((m <GetFactor-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader loadcell_calibration-srv:lbs_reading-val is deprecated.  Use loadcell_calibration-srv:lbs_reading instead.")
  (lbs_reading m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetFactor-request>) ostream)
  "Serializes a message object of type '<GetFactor-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'lbs_reading))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetFactor-request>) istream)
  "Deserializes a message object of type '<GetFactor-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lbs_reading) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetFactor-request>)))
  "Returns string type for a service object of type '<GetFactor-request>"
  "loadcell_calibration/GetFactorRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetFactor-request)))
  "Returns string type for a service object of type 'GetFactor-request"
  "loadcell_calibration/GetFactorRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetFactor-request>)))
  "Returns md5sum for a message object of type '<GetFactor-request>"
  "dc5041cd9b38a6c10e3ab905f7b1c263")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetFactor-request)))
  "Returns md5sum for a message object of type 'GetFactor-request"
  "dc5041cd9b38a6c10e3ab905f7b1c263")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetFactor-request>)))
  "Returns full string definition for message of type '<GetFactor-request>"
  (cl:format cl:nil "float64 lbs_reading~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetFactor-request)))
  "Returns full string definition for message of type 'GetFactor-request"
  (cl:format cl:nil "float64 lbs_reading~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetFactor-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetFactor-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetFactor-request
    (cl:cons ':lbs_reading (lbs_reading msg))
))
;//! \htmlinclude GetFactor-response.msg.html

(cl:defclass <GetFactor-response> (roslisp-msg-protocol:ros-message)
  ((factor
    :reader factor
    :initarg :factor
    :type cl:float
    :initform 0.0)
   (is_done
    :reader is_done
    :initarg :is_done
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass GetFactor-response (<GetFactor-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetFactor-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetFactor-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name loadcell_calibration-srv:<GetFactor-response> is deprecated: use loadcell_calibration-srv:GetFactor-response instead.")))

(cl:ensure-generic-function 'factor-val :lambda-list '(m))
(cl:defmethod factor-val ((m <GetFactor-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader loadcell_calibration-srv:factor-val is deprecated.  Use loadcell_calibration-srv:factor instead.")
  (factor m))

(cl:ensure-generic-function 'is_done-val :lambda-list '(m))
(cl:defmethod is_done-val ((m <GetFactor-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader loadcell_calibration-srv:is_done-val is deprecated.  Use loadcell_calibration-srv:is_done instead.")
  (is_done m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetFactor-response>) ostream)
  "Serializes a message object of type '<GetFactor-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'factor))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_done) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetFactor-response>) istream)
  "Deserializes a message object of type '<GetFactor-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'factor) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:slot-value msg 'is_done) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetFactor-response>)))
  "Returns string type for a service object of type '<GetFactor-response>"
  "loadcell_calibration/GetFactorResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetFactor-response)))
  "Returns string type for a service object of type 'GetFactor-response"
  "loadcell_calibration/GetFactorResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetFactor-response>)))
  "Returns md5sum for a message object of type '<GetFactor-response>"
  "dc5041cd9b38a6c10e3ab905f7b1c263")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetFactor-response)))
  "Returns md5sum for a message object of type 'GetFactor-response"
  "dc5041cd9b38a6c10e3ab905f7b1c263")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetFactor-response>)))
  "Returns full string definition for message of type '<GetFactor-response>"
  (cl:format cl:nil "float64 factor~%bool is_done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetFactor-response)))
  "Returns full string definition for message of type 'GetFactor-response"
  (cl:format cl:nil "float64 factor~%bool is_done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetFactor-response>))
  (cl:+ 0
     8
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetFactor-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetFactor-response
    (cl:cons ':factor (factor msg))
    (cl:cons ':is_done (is_done msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetFactor)))
  'GetFactor-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetFactor)))
  'GetFactor-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetFactor)))
  "Returns string type for a service object of type '<GetFactor>"
  "loadcell_calibration/GetFactor")