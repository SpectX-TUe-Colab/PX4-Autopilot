// --------------------------------------------------
// This file was autogenerated, do NOT modify by hand
// --------------------------------------------------

#ifndef EKF_STATE_H
#define EKF_STATE_H

#include <matrix/math.hpp>

namespace estimator
{
struct StateSample {
	matrix::Quaternion<float> quat_nominal{};
	matrix::Vector3<float> vel{};
	matrix::Vector3<float> pos{};
	matrix::Vector3<float> gyro_bias{};
	matrix::Vector3<float> accel_bias{};
	matrix::Vector3<float> mag_I{};
	matrix::Vector3<float> mag_B{};
	matrix::Vector2<float> wind_vel{};
	float terrain_vpos{};

	matrix::Vector<float, 25> Data() const {
		matrix::Vector<float, 25> state;
		state.slice<4, 1>(0, 0) = quat_nominal;
		state.slice<3, 1>(4, 0) = vel;
		state.slice<3, 1>(7, 0) = pos;
		state.slice<3, 1>(10, 0) = gyro_bias;
		state.slice<3, 1>(13, 0) = accel_bias;
		state.slice<3, 1>(16, 0) = mag_I;
		state.slice<3, 1>(19, 0) = mag_B;
		state.slice<2, 1>(22, 0) = wind_vel;
		state.slice<1, 1>(24, 0) = terrain_vpos;
		return state;
	};

	const matrix::Vector<float, 25>& vector() const {
		return *reinterpret_cast<matrix::Vector<float, 25>*>(const_cast<float*>(reinterpret_cast<const float*>(&quat_nominal)));
	};

};
static_assert(sizeof(matrix::Vector<float, 25>) == sizeof(StateSample), "state vector doesn't match StateSample size");

struct IdxDof { unsigned idx; unsigned dof; };
namespace State {
	static constexpr IdxDof quat_nominal{0, 3};
	static constexpr IdxDof vel{3, 3};
	static constexpr IdxDof pos{6, 3};
	static constexpr IdxDof gyro_bias{9, 3};
	static constexpr IdxDof accel_bias{12, 3};
	static constexpr IdxDof mag_I{15, 3};
	static constexpr IdxDof mag_B{18, 3};
	static constexpr IdxDof wind_vel{21, 2};
	static constexpr IdxDof terrain_vpos{23, 1};
	static constexpr uint8_t size{24};
};
}
#endif // !EKF_STATE_H
