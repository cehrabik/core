<?hh

use Senary\Routing\Route;

class RouteTest extends TestCase
{

    /**
     * Setup
     */
    public function setUp()
    {
        parent::setUp();
        $this->route = new Route('GET', '/foo');
    }


    /**
     * @test
     */
    public function gets_and_sets_method()
    {
        $this->assertSame('GET', $this->route->getMethod());

        $this->route->setMethod('POST');
        $this->assertSame('POST' ,$this->route->getMethod());
    }


    /**
     * @test
     */
    public function get_and_set_method_alias()
    {
        $this->assertSame('GET', $this->route->method());

        $this->route->method('POST');
        $this->assertSame('POST' ,$this->route->getMethod());
    }


    /**
     * @test
     */
    public function get_and_set_uri()
    {
        $this->assertSame('/foo', $this->route->getUri());

        $this->route->setUri('/bar');
        $this->assertSame('/bar', $this->route->getUri());
    }


    /**
     * @test
     */
    public function get_and_set_uri_alias()
    {
        $this->assertSame('/foo', $this->route->uri());

        $this->route->uri('/bar');
        $this->assertSame('/bar', $this->route->getUri());
    }

}
