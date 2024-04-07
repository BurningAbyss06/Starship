#pragma once

#include <cstdint>
#include <Resource.h>
#include <libultraship/libultra/types.h>

namespace SF64 {

struct Vec2f {
    float x, y;
    Vec2f(float x, float y) : x(x), y(y) {}
};

struct Vec3f {
    float x, y, z;
    Vec3f(float x, float y, float z) : x(x), y(y), z(z) {}
};

struct Vec3s {
    int16_t x, y, z;
    Vec3s(int16_t x, int16_t y, int16_t z) : x(x), y(y), z(z) {}
};

struct Vec3i {
    int32_t x, y, z;
    Vec3i(int32_t x, int32_t y, int32_t z) : x(x), y(y), z(z) {}
};

struct Vec4f {
    float x, y, z, w;
    Vec4f(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
};

struct Vec4s {
    int16_t x, y, z, w;
    Vec4s(int16_t x, int16_t y, int16_t z, int16_t w) : x(x), y(y), z(z), w(w) {}
};

typedef std::variant<uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t, uint64_t, float, double, Vec2f, Vec3f, Vec3s, Vec3i, Vec4f, Vec4s> GenericArrayData;

enum class ArrayType {
    u8, s8, u16, s16, u32, s32, u64, f32, f64, Vec2f, Vec3f, Vec3s, Vec3i, Vec4f, Vec4s,
};

class GenericArray : public LUS::Resource<GenericArrayData> {
  public:
    using Resource::Resource;

    GenericArray() : Resource(std::shared_ptr<LUS::ResourceInitData>()) {}

    GenericArrayData* GetPointer();
    size_t GetPointerSize();

    std::vector<GenericArrayData> mData;
};
}