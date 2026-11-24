
#include "VectorConversions.h"

// #include <glm/glm.hpp>

#include "Vector2.h"
#include "Vector2Int.h"
#include "Vector3.h"
#include "Vector3Int.h"
#include "Vector4.h"
#include "Vector4Int.h"

namespace ZMath {
	Vector2 fromVec2_GLM(const glm::vec2& _v) {
		return Vector2 { _v.x, _v.y };
	}

	glm::vec2 toVec2_GLM(const Vector2& _v) {
		return glm::vec2 { _v.x, _v.y };
	}

	Vector2Int fromVec2Int_GLM(const glm::ivec2& _v) {
		return Vector2Int { _v.x, _v.y };
	}

	glm::ivec2 toVec2Int_GLM(const Vector2Int& _v) {
		return glm::ivec2 { _v.x, _v.y };
	}

	Vector3 fromVec3_GLM(const glm::vec3& _v) {
		return Vector3 { _v.x, _v.y, _v.z };
	}

	glm::vec3 toVec3_GLM(const Vector3& _v) {
		return glm::vec3 { _v.x, _v.y, _v.z };
	}

	Vector3Int fromVec3Int_GLM(const glm::ivec3& _v) {
		return Vector3Int { _v.x, _v.y, _v.z };
	}

	glm::ivec3 toVec3Int_GLM(const Vector3Int& _v) {
		return glm::ivec3 { _v.x, _v.y, _v.z };
	}

	Vector4 fromVec4_GLM(const glm::vec4& _v) {
		return Vector4 { _v.x, _v.y, _v.z, _v.w };
	}

	glm::vec4 toVec4_GLM(const Vector4& _v) {
		return glm::vec4 { _v.x, _v.y, _v.z, _v.w };
	}

	Vector4Int fromVec4Int_GLM(const glm::ivec4& _v) {
		return Vector4Int { _v.x, _v.y, _v.z, _v.w };
	}

	glm::ivec4 toVec4Int_GLM(const Vector4Int& _v) {
		return glm::ivec4 { _v.x, _v.y, _v.z, _v.w };
	}
}

