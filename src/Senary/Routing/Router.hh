<?hh // strict
namespace Senary\Routing;

class Router
{

    /**
     * Route factory
     * @var RouteFactory
     */
    protected RouteFactory $factory;


    /**
     * Registered routes
     * @var array
     */
    protected array<Route> $routes;


    /**
     * Constructor
     *
     * @param  array        $routes
     * @param  RouteFactory $factory
     * @return void
     */
    public function __construct(array<Route> $routes = [], ?RouteFactory $factory = null) :void
    {
        $this->routes = $routes;
        $this->factory = $factory ?: new RouteFactory();
    }


    /**
     * Get registered routes
     *
     * @return array
     */
    public function getRoutes() :array<Route>
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
