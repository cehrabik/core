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
        $this->routes->push($route);

        return $route;
    }


    /**
     * Register new GET route
     *
     * @param  string $uri
     * @return Route
     */
    public function get(string $uri) :Route
    {
        return $this->register('GET', $uri);
    }


    /**
     * Register new POST route
     *
     * @param  string $uri
     * @return Route
     */
    public function post(string $uri) :Route
    {
        return $this->register('POST', $uri);
    }


    /**
     * Register new PUT route
     *
     * @param  string $uri
     * @return Route
     */
    public function put(string $uri) :Route
    {
        return $this->register('PUT', $uri);
    }


    /**
     * Register new DELETE route
     *
     * @param  string $uri
     * @return Route
     */
    public function delete(string $uri) :Route
    {
        return $this->register('DELETE', $uri);
    }


    /**
     * Register new HEAD route
     *
     * @param  string $uri
     * @return Route
     */
    public function head(string $uri) :Route
    {
        return $this->register('HEAD', $uri);
    }


    /**
     * Register new OPTIONS route
     *
     * @param  string $uri
     * @return Route
     */
    public function options(string $uri) :Route
    {
        return $this->register('OPTIONS', $uri);
    }

}
