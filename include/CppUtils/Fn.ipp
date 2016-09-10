#include <algorithm>


namespace CppUtils
{


template<typename T, typename Container, typename Accumulator>
T accumulate(const T & initial_value, const Container & container, const Accumulator & accumulator)
{
    return std::accumulate(
        container.begin(),
        container.end(),
        initial_value,
        accumulator);
}


template<typename T, typename Container, typename Function>
std::vector<T> transform(const Container & container, const Function & function)
{
    std::vector<T> result(container.size());

    std::transform(
        container.begin(),
        container.end(),
        result.begin(),
        function);

    return result;
}


} // namespace CppUtils