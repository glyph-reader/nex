#ifndef BOUNDINGSPHERE_H_INCLUDE
#define BOUNDINGSPHERE_H_INCLUDE

#include <nex/math/mathhelper.h>
#include <nex/math/vec3.h>

namespace nx
{
    /**
     * @brief Defines a sphere.
     */
    class BoundingSphere
    {
    public:

        /**
         * @brief Creates a new instance of BoundingSphere.
         */
        BoundingSphere();

        /**
         * @brief Creates a new instance of BoundingSphere.
         * @param center = Center point of the sphere.
         * @param radius = Radius of the sphere.
         */
        BoundingSphere(const vec3f center, const float radius);

        /**
         * @brief Creates a BoundingSphere that contains the two specified BoundingSphere instances.
         * @param original = BoundingSphere to be merged.
         * @param additional = BoundingSphere to be merged.
         * @return the resulting sphere.
         */
        static BoundingSphere createMerged(const BoundingSphere& original, const BoundingSphere& additional);

        /**
         * @brief The center point of the sphere.
         */
        vec3f center;

        /**
         * @brief The radius of the sphere.
         */
        float radius;

    };
} //namespace nx

#endif // BOUNDINGSPHERE_H_INCLUDE
