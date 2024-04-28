#pragma once

namespace ly {
    class Object {
       public:
        Object();
        virtual ~Object();

        void Destroy();
        bool IsPendingDestroy() const { return m_IsPendingDestroy; };

       public:
        bool m_IsPendingDestroy;
    };
}  // namespace ly
