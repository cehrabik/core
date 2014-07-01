<?hh

use Senary\Routing\RouteManager;

class RouteManagerTest extends TestCase
{

    /**
     * Setup
     */
    public function setUp()
    {
        parent::setUp();
        $this->router = new RouteManager();
    }


    /**
     * @test
     */
    public function get_registered_routes()
    {
        $this->assertInstanceOf('Senary\Support\Listing', $this->router->getRoutes());
        $this->assertSame([], $this->router->getRoutes()->all());
    }


    /**
     * Test given route
     * (assuming first route creation)
     *
     * @param \Senary\Routing\Route $route
     * @return void
     */
    protected function assertRoute($route)
    {
        $this->assertInstanceOf('Senary\Routing\Route', $route);
        $this->assertSame($route, $this->router->getRoutes()->first());
    }


    /**
     * @test
     */
    public function register_new_route()
    {
        $route = $this->router->register('GET', '/foo');
        $this->assertRoute($route);
    }


    /**
     * @test
     */
    public function register_get_route()
    {
        $route = $this->router->get('/getFoo');

        $this->assertRoute($route);
        $this->assertSame('GET', $route->getMethod());
    }


    /**
     * @test
     */
    public function register_post_route()
    {
        $route = $this->router->post('postFoo');

        $this->assertRoute($route);
        $this->assertSame('POST', $route->getMethod());
    }


    /**
     * @test
     */
    public function register_put_route()
    {
        $route = $this->router->put('putFoo');

        $this->assertRoute($route);
        $this->assertSame('PUT', $route->getMethod());
    }


    /**
     * @test
     */
    public function register_delete_route()
    {
        $route = $this->router->delete('deleteFoo');

        $this->assertRoute($route);
        $this->assertSame('DELETE', $route->getMethod());
    }


    /**
     * @test
     */
    public function register_head_route()
    {
        $route = $this->router->head('headFoo');

        $this->assertRoute($route);
        $this->assertSame('HEAD', $route->getMethod());
    }


    /**
     * @test
     */
    public function register_options_route()
    {
        $route = $this->router->options('optionsFoo');

        $this->assertRoute($route);
        $this->assertSame('OPTIONS', $route->getMethod());
    }

}
