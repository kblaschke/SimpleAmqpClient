#include "Message.h"

#include <cstring>

namespace AmqpClient {

Message::Message()
{
}

Message::Message(amqp_bytes_t body, amqp_basic_properties_t* properties) :
	m_body(body), m_properties(*properties)
{
}

Message::~Message()
{
	amqp_bytes_free(m_body);
	if (ContentTypeIsSet()) amqp_bytes_free(m_properties.content_type);
	if (ContentEncodingIsSet()) amqp_bytes_free(m_properties.content_encoding);
	if (CorrelationIdIsSet()) amqp_bytes_free(m_properties.correlation_id);
	if (ReplyToIsSet()) amqp_bytes_free(m_properties.reply_to);
	if (ExpirationIsSet()) amqp_bytes_free(m_properties.expiration);
	if (MessageIdIsSet()) amqp_bytes_free(m_properties.message_id);
	if (TypeIsSet()) amqp_bytes_free(m_properties.type);
	if (UserIdIsSet()) amqp_bytes_free(m_properties.user_id);
	if (AppIdIsSet()) amqp_bytes_free(m_properties.app_id);
	if (ClusterIdIsSet()) amqp_bytes_free(m_properties.cluster_id);
}

std::string Message::Body() const
{
    if (m_body.bytes == NULL)
        return std::string();
    else
        return std::string((char*)m_body.bytes, m_body.len);
}
void Message::Body(const std::string& body)
{
	m_body = amqp_bytes_malloc_dup(amqp_cstring_bytes(body.c_str()));
}

std::string Message::ContentType() const
{
    if (ContentTypeIsSet())
        return std::string((char*)m_properties.content_type.bytes, m_properties.content_type.len);
    else
        return std::string();
}

void Message::ContentType(const std::string& content_type)
{
	if (ContentTypeIsSet()) amqp_bytes_free(m_properties.content_type);
	m_properties.content_type = amqp_bytes_malloc_dup(amqp_cstring_bytes(content_type.c_str()));
    m_properties._flags |= AMQP_BASIC_CONTENT_TYPE_FLAG;
}


std::string Message::ContentEncoding() const
{
    if (ContentEncodingIsSet())
        return std::string((char*)m_properties.content_encoding.bytes, m_properties.content_encoding.len);
    else
        return std::string();
}

void Message::ContentEncoding(const std::string& content_encoding)
{
	if (ContentEncodingIsSet()) amqp_bytes_free(m_properties.content_encoding);
	m_properties.content_encoding = amqp_bytes_malloc_dup(amqp_cstring_bytes(content_encoding.c_str()));
    m_properties._flags |= AMQP_BASIC_CONTENT_ENCODING_FLAG;
}

Message::delivery_mode_t Message::DeliveryMode() const
{
    if (DeliveryModeIsSet())
        return (delivery_mode_t)m_properties.delivery_mode;
    else
        return (delivery_mode_t)0;
}
void Message::DeliveryMode(delivery_mode_t delivery_mode)
{
    m_properties.delivery_mode = delivery_mode;
    m_properties._flags |= AMQP_BASIC_DELIVERY_MODE_FLAG;
}

uint8_t Message::Priority() const
{
    if (PriorityIsSet())
        return m_properties.priority;
    else
        return 0;
}
void Message::Priority(uint8_t priority)
{
    m_properties.priority = priority;
    m_properties._flags |= AMQP_BASIC_PRIORITY_FLAG;
}

std::string Message::CorrelationId() const
{
    if (CorrelationIdIsSet())
        return std::string((char*)m_properties.correlation_id.bytes, m_properties.correlation_id.len);
    else
        return std::string();
}
void Message::CorrelationId(const std::string& correlation_id)
{
	if (CorrelationIdIsSet()) amqp_bytes_free(m_properties.correlation_id);
	m_properties.correlation_id = amqp_bytes_malloc_dup(amqp_cstring_bytes(correlation_id.c_str()));
    m_properties._flags |= AMQP_BASIC_CORRELATION_ID_FLAG;
}

std::string Message::ReplyTo() const
{
    if (ReplyToIsSet())
        return std::string((char*)m_properties.reply_to.bytes, m_properties.reply_to.len);
    else
        return std::string();
}
void Message::ReplyTo(const std::string& reply_to)
{
	if (ReplyToIsSet()) amqp_bytes_free(m_properties.reply_to);
	m_properties.reply_to = amqp_bytes_malloc_dup(amqp_cstring_bytes(reply_to.c_str()));
    m_properties._flags |= AMQP_BASIC_REPLY_TO_FLAG;
}

std::string Message::Expiration() const
{
    if (ExpirationIsSet())
        return std::string((char*)m_properties.expiration.bytes, m_properties.expiration.len);
    else
        return std::string();
}
void Message::Expiration(const std::string& expiration)
{
	if (ExpirationIsSet()) amqp_bytes_free(m_properties.expiration);
	m_properties.expiration = amqp_bytes_malloc_dup(amqp_cstring_bytes(expiration.c_str()));
    m_properties._flags |= AMQP_BASIC_EXPIRATION_FLAG;
}

std::string Message::MessageId() const
{
    if (MessageIdIsSet())
        return std::string((char*)m_properties.message_id.bytes, m_properties.message_id.len);
    else
        return std::string();
}
void Message::MessageId(const std::string& message_id)
{
	if (MessageIdIsSet()) amqp_bytes_free(m_properties.message_id);
	m_properties.message_id = amqp_bytes_malloc_dup(amqp_cstring_bytes(message_id.c_str()));
    m_properties._flags |= AMQP_BASIC_MESSAGE_ID_FLAG;
}

uint64_t Message::Timestamp() const
{
    if (ReplyToIsSet())
        return m_properties.timestamp;
    else
        return 0;
}
void Message::Timestamp(uint64_t timestamp)
{
    m_properties.timestamp = timestamp;
    m_properties._flags |= AMQP_BASIC_TIMESTAMP_FLAG;
}

std::string Message::Type() const
{
    if (TypeIsSet())
        return std::string((char*)m_properties.type.bytes, m_properties.type.len);
    else
        return std::string();
}
void Message::Type(const std::string& type)
{
	if (TypeIsSet()) amqp_bytes_free(m_properties.type);
	m_properties.type = amqp_bytes_malloc_dup(amqp_cstring_bytes(type.c_str()));
    m_properties._flags |= AMQP_BASIC_TYPE_FLAG;
}

std::string Message::UserId() const
{
    if (UserIdIsSet())
        return std::string((char*)m_properties.user_id.bytes, m_properties.user_id.len);
    else
        return std::string();
}
void Message::UserId(const std::string& user_id)
{
	if (UserIdIsSet()) amqp_bytes_free(m_properties.user_id);
	m_properties.user_id = amqp_bytes_malloc_dup(amqp_cstring_bytes(user_id.c_str()));
    m_properties._flags |= AMQP_BASIC_USER_ID_FLAG;
}

std::string Message::AppId() const
{
    if (AppIdIsSet())
        return std::string((char*)m_properties.app_id.bytes, m_properties.app_id.len);
    else
        return std::string();
}
void Message::AppId(const std::string& app_id)
{
	if (AppIdIsSet()) amqp_bytes_free(m_properties.app_id);
	m_properties.app_id = amqp_bytes_malloc_dup(amqp_cstring_bytes(app_id.c_str()));
    m_properties._flags |= AMQP_BASIC_APP_ID_FLAG;
}

std::string Message::ClusterId() const
{
    if (ClusterIdIsSet())
        return std::string((char*)m_properties.cluster_id.bytes, m_properties.cluster_id.len);
    else
        return std::string();
}
void Message::ClusterId(const std::string& cluster_id)
{
	if (AppIdIsSet()) amqp_bytes_free(m_properties.cluster_id);
	m_properties.cluster_id = amqp_bytes_malloc_dup(amqp_cstring_bytes(cluster_id.c_str()));
    m_properties._flags |= AMQP_BASIC_CLUSTER_ID_FLAG;
}

} // namespace AmqpClient
