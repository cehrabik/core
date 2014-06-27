<?hh

use Senary\Routing\Router;

class RouterTest extends TestCase
{

    /**
     * Setup
     */
    public function setUp()
    {
        parent::setUp();
        $this->router = new Router();
    }


    /**
     * @test
     */
    public function get_registered_routes()
    {
        $this->assertEquals(Vector{}, $this->router->getRoutes());
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
