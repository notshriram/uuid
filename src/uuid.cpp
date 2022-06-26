#include "uuid.h"
#include <random>

//instantiate static member
std::unordered_set<std::uint64_t> UUID::uuid_set;

std::uint64_t UUID::get_uuid() const
{
    return uuid;
}

void UUID::set_uuid(std::uint64_t uuid)
{
    this->uuid = uuid;
}

UUID::UUID()
{
    //generate a random uuid using mt19337
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<std::uint64_t> dist(0, std::numeric_limits<std::uint64_t>::max());
    uuid = dist(mt);
    while (uuid_set.contains(uuid))
    {
        uuid = dist(mt);
    }
    uuid_set.insert(uuid);
}

UUID& UUID::operator=(const UUID& uuid)
{
    this->uuid = uuid.uuid;
    return *this;
}

UUID::UUID(std::uint64_t uuid)
{
    this->uuid = uuid;
    uuid_set.insert(uuid);
}

UUID& UUID::operator=(std::uint64_t uuid)
{
    this->uuid = uuid;
    return *this;
}

//uint64t cast operator
UUID::operator std::uint64_t() const
{
    return this->uuid;
}

// operator ==
bool UUID::operator==(const UUID& uuid) const
{
    return this->uuid == uuid.uuid;
}

// operator !=
bool UUID::operator!=(const UUID& uuid) const
{
    return this->uuid != uuid.uuid;
}

// operator <
bool UUID::operator<(const UUID& uuid) const
{
    return this->uuid < uuid.uuid;
}

// operator >
bool UUID::operator>(const UUID& uuid) const
{
    return this->uuid > uuid.uuid;
}

// operator <=
bool UUID::operator<=(const UUID& uuid) const
{
    return this->uuid <= uuid.uuid;
}

// operator >=
bool UUID::operator>=(const UUID& uuid) const
{
    return this->uuid >= uuid.uuid;
}

std::ostream& UUID::operator<<(std::ostream& os) const
{
    os << uuid;
    return os;
}

std::istream& UUID::operator>>(std::istream& is)
{
    is >> uuid;
    return is;
}

std::string UUID::to_string() const
{
    std::stringstream ss;
    ss << uuid;
    return ss.str();
}

