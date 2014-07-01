<?hh // strict
namespace Senary\Routing;

use Senary\Support\Listing;

class RouteManager
{

    /**
     * Route factory
     * @var RouteFactory
     */
    protected RouteFactory $factory;


    /**
     * Registered routes
     * @var Listing
     */
    protected Listing<Route> $routes;


    /**
     * Constructor
     *
     * @param  Listing      $routes
     * @param  RouteFactory $factory
     * @return void
     */
    public function __construct(?Listing<Route> $routes = null, ?RouteFactory $factory = null) :void
    {
        $this->routes = $routes ?: new Listing();
        $this->factory = $factory ?: new RouteFactory();
    }


    /**
     * Get registered routes
     *
     * @return array
     */
    public function getRoutes() :Listing<Route>
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
