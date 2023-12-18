///|/ Copyright (c) Prusa Research 2023 Enrico Turri @enricoturri1966
///|/
///|/ libvgcode is released under the terms of the AGPLv3 or higher
///|/
#ifndef VGCODE_COGMARKER_HPP
#define VGCODE_COGMARKER_HPP

#include "../include/Types.hpp"

#if !ENABLE_NEW_GCODE_VIEWER_NO_COG_AND_TOOL_MARKERS

namespace libvgcode {

class CogMarker
{
public:
    CogMarker() = default;
    ~CogMarker();
    CogMarker(const CogMarker& other) = delete;
    CogMarker(CogMarker&& other) = delete;
    CogMarker& operator = (const CogMarker& other) = delete;
    CogMarker& operator = (CogMarker&& other) = delete;

    //
    // Initialize geometry on gpu
    //
    void init(uint8_t resolution, float radius);
    void render();

    //
    // Update values used to calculate the center of gravity
    //
    void update(const Vec3& position, float mass);

    //
    // Reset values used to calculate the center of gravity
    //
    void reset();

    //
    // Return the calculated center of gravity
    //
    Vec3 get_position() const;

private:
    //
    // Values used to calculate the center of gravity
    //
    float m_total_mass{ 0.0f };
    Vec3 m_total_position{ 0.0f, 0.0f, 0.0f };

    uint16_t m_indices_count{ 0 };
    unsigned int m_vao_id{ 0 };
    unsigned int m_vbo_id{ 0 };
    unsigned int m_ibo_id{ 0 };
};

} // namespace libvgcode

#endif // !ENABLE_NEW_GCODE_VIEWER_NO_COG_AND_TOOL_MARKERS

#endif // VGCODE_COGMARKER_HPP