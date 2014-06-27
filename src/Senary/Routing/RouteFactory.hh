<?hh // strict
namespace Senary\Routing;

class RouteFactory
{

    /**
     * Make new route
     *
     * @param  string $method
     * @param  string $uri
     * @return Route
     */
    public function make(string $method, string $uri) :Route
    {
        return new Route($method, $uri);
    }

}
