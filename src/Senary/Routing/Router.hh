<?hh // strict
namespace Senary\Routing;

use Senary\Support\Hash;

class Router
{

    /**
     * Route factory
     * @var RouteFactory
     */
    protected RouteFactory $factory;


    /**
     * Registered routes
     * @var Hash
     */
    protected Hash<int, Route> $routes;


    /**
     * Constructor
     *
     * @param  Hash         $routes
     * @param  RouteFactory $factory
     * @return void
     */
    public function __construct(?Hash<int, Route> $routes = null, ?RouteFactory $factory = null) :void
    {
        $this->routes = $routes ?: new Hash();
        $this->factory = $factory ?: new RouteFactory();
    }


    /**
     * Get registered routes
     *
     * @return array
     */
    public function getRoutes() :Hash<int, Route>
    {
        return $this->routes;
    }


    /**
     * Register new route
     *
     * @param  string $method
     * @param  string $uri
     * @return Route
     */
    public function register(string $method, string $uri) :Route
    {
        $route = $this->factory->make($method, $uri);

        return $route;
    }

}
