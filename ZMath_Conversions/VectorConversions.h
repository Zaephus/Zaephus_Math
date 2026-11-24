
#pragma once

namespace glm {
    struct vec2 {
        float x;
        float y;
    };
    struct ivec2 {
        int x;
        int y;
    };

    struct vec3 {
        float x;
        float y;
        float z;
    };
    struct ivec3 {
        int x;
        int y;
        int z;
    };

    struct vec4 {
        float x;
        float y;
        float z;
        float w;
    };
    struct ivec4 {
        int x;
        int y;
        int z;
        int w;
    };
}

namespace ZMath {
    struct Vector2;
    struct Vector2Int;

    struct Vector3;
    struct Vector3Int;

    struct Vector4;
    struct Vector4Int;

    Vector2 fromVec2_GLM(const glm::vec2& _v);
    glm::vec2 toVec2_GLM(const Vector2& _v);

    Vector2Int fromVec2Int_GLM(const glm::ivec2& _v);
    glm::ivec2 toVec2Int_GLM(const Vector2Int& _v);

    Vector3 fromVec3_GLM(const glm::vec3& _v);
    glm::vec3 toVec3_GLM(const Vector3& _v);

    Vector3Int fromVec3Int_GLM(const glm::ivec3& _v);
    glm::ivec3 toVec3Int_GLM(const Vector3Int& _v);

    Vector4 fromVec4_GLM(const glm::vec4& _v);
    glm::vec4 toVec4_GLM(const Vector4& _v);

    Vector4Int fromVec4Int_GLM(const glm::ivec4& _v);
    glm::ivec4 toVec4Int_GLM(const Vector4Int& _v);
}