#ifndef TYPE_TRAITS_GUARD
#define TYPE_TRAITS_GUARD

#include <type_traits>

namespace mystl
{

// helper struct
template<class T, T v>
struct m_integral_constant
{
    static constexpr T value = v;
};

template<bool b>
using m_bool_constant = m _integral_constant<bool, b>;

typedef m_bool_constant<true> m_true_type;
typedef m_bool_constant<false> m_false_type;

/**********************************************************/

// type traites

// is_pair

// -- forward declaration begin
template<class T1, class T2>
struct pair;
// -- forward declartion end

template<class T>
struct is_pair : mystl::m_false_type {};

template<class T1, class T2>
struct is_pair<mystl::pair<T1, T2>> : mystl:m_true_type {};

} // namespace mystl

#endif 