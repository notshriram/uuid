#pragma once
#include <cstdint>
#include <string>
#include <unordered_set>
#include <istream>
#include <ostream>
#include <string>
#include <sstream>

class UUID
{
private:
    std::uint64_t uuid;
    static std::unordered_set<std::uint64_t> uuid_set;
public:
    UUID();
    UUID(std::uint64_t uuid);
    UUID(const UUID& uuid);
    UUID& operator=(const UUID& uuid);
    UUID& operator=(std::uint64_t uuid);
    bool operator==(const UUID& uuid) const;
    bool operator!=(const UUID& uuid) const;
    bool operator<(const UUID& uuid) const;
    bool operator>(const UUID& uuid) const;
    bool operator<=(const UUID& uuid) const;
    bool operator>=(const UUID& uuid) const;
    std::uint64_t get_uuid() const;
    operator std::uint64_t() const;
    void set_uuid(std::uint64_t uuid);
    std::string to_string() const;
    static UUID from_string(const std::string& str);
    std::ostream& operator<<(std::ostream& os) const;
    std::istream& operator>>(std::istream& is);
};
namespace std
{
    template <>
    struct hash<UUID>
    {
        size_t operator()(const UUID& uuid) const
        {
            return hash<std::uint64_t>()((uint64_t)uuid);
        }
    };
}
