#ifndef QUATERNION_H_INCLUDE
#define QUATERNION_H_INCLUDE

#ifndef VEC3_H_INCLUDE
#include <nex/math/vec3.h>
#endif

namespace nx
{
template <typename T>
class Quaternion
{
public:

    /**
     * @brief Construct an identity matrix.
     */
    Quaternion();

    /**
     * @brief Construct a quaternion with the specified values.
     * @param x = x value.
     * @param y = y value.
     * @param z = z value.
     * @param w = w value.
     */
    Quaternion(const T x, const T y, const T z, const T w);

    /**
     * it's called only when U != T.
     * A call to this constructor will fail to compile if U
     * is not convertible to T.
     */
    template <typename U>
    explicit Quaternion(const Quaternion<U>& vector);

    T& operator=(const T& lhs) & {
        x = lhs.x;
        y = lhs.y;
        z = lhs.z;
        w = lhs.w;
        return *this;
    }

    /**
     * @brief Calculates the length of a Quaternion.
     * @return the length.
     */
    T length() const;

    /**
     * @brief Calculates the length squared of a Quaternion.
     * @return the length squared.
     */
    T lengthSquared() const;

    /**
     * @brief Divides each component of the quaternion by the length of the quaternion.
     */
    void normalize();

    /**
     * @brief Transforms this Quaternion into its conjugate.
     */
    void conjugate();

    /**
     * @brief Inverses the current Quaternion.
     */
    void inverse();

    /**
     * @brief Calculates the dot product of two Quaternions.
     * @param other = The other quaternion.
     * @return the dot product.
     */
    T dot(const Quaternion<T>& other);

    /**
     * @brief Divides each component of the quaternion by the length of the quaternion.
     * @param value = the quaternion to normalize.
     * @return the normalized quaternion.
     */
    static Quaternion<T> normalize(const Quaternion& value);

    /**
     * @brief Transforms this Quaternion into its conjugate.
     * @param value = The Quaternion of which to return the conjugate.
     * @return the conjugate.
     */
    static Quaternion<T> conjugate(const Quaternion& value);

    /**
     * @brief Returns the inverse of a Quaternion.
     * @param value = Quaternion to calculate the inverse of.
     * @return the inverse quaternion.
     */
    static Quaternion<T> inverse(const Quaternion& value);

    /**
     * @brief Creates a Quaternion from a vector and an angle to rotate about the vector.
     * @param axis = The vector to rotate around.
     * @param angle = The angle to rotate around the vector in radians.
     * @return the rotation quaternion.
     */
    static Quaternion<T> createFromAxisAngle(Vec3<T> axis, const T angle);

    /**
     * @brief Creates a new Quaternion from specified yaw, pitch, and roll angles.
     * @param yaw = The yaw angle, in radians, around the y-axis.
     * @param pitch = The pitch angle, in radians, around the x-axis.
     * @param roll = The roll angle, in radians, around the z-axis.
     * @return the rotation quaternion.
     */
    static Quaternion<T> createFromYawPitchRoll(const T yaw, const T pitch, const T roll);

    /**
     * @brief Calculates the dot product of two Quaternions.
     * @param left = Left source quaternion.
     * @param right = Right source quaternion.
     * @return the dot product.
     */
    static T dot(const Quaternion<T>& left, const Quaternion<T>& right);

    /**
     * @brief Interpolates between two quaternions, using spherical linear interpolation.
     * @param previous = The previous quaternion.
     * @param current = The current quaternion.
     * @param amount = The interpolation weight.
     * @return the interpolated quaternion.
     */
    static Quaternion<T> slerp(const Quaternion<T>& previous,  const Quaternion<T>& current, const T amount);

    /**
     * @brief Linearly interpolates between two quaternions.
     * @param previous = The previous quaternion.
     * @param current = The current quaternion.
     * @param amount = The interpolation weight.
     * @return the interpolated quaternion.
     */
    static Quaternion<T> lerp(const Quaternion<T>& previous,  const Quaternion<T>& current, const T amount);

    /**
     * @brief Concatenates two Quaternions; the result represents the left rotation followed by the right rotation.
     * @param left = The first Quaternion rotation in the series.
     * @param right = The second Quaternion rotation in the series.
     * @return the concententated quaternion.
     */
    static Quaternion<T> concatenate(const Quaternion<T>& left, const Quaternion<T>& right);

    T x;
    T y;
    T z;
    T w;
}; //class Quaternion

#include <nex/math/quaternion.inl>

typedef Quaternion<float> quatf;
typedef Quaternion<double> quatd;

} // namespace nx

#endif // QUATERNION_H_INCLUDE
