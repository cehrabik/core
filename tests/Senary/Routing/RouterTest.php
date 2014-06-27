<?hh

use Senary\Routing\RouteManager;

class RouterTest extends TestCase
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
        $this->assertSame([], $this->router->getRoutes()->all());
    }


    /**
     * @test
     */
    public function register_new_route()
    {
        $route = $this->router->register('GET', '/foo');

        $this->assertInstanceOf('Senary\Routing\Route', $route);
    }

}
