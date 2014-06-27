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
     * @var Vector
     */
    protected Vector<Route> $routes;


    /**
     * Constructor
     *
     * @param  Vector       $routes
     * @param  RouteFactory $factory
     * @return void
     */
    public function __construct(Vector<Route> $routes = Vector{}, ?RouteFactory $factory = null) :void
    {
        $this->routes = $routes;
        $this->factory = $factory ?: new RouteFactory();
    }


    /**
     * Get registered routes
     *
     * @return Vector
     */
    public function getRoutes() :Vector<Route>
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
