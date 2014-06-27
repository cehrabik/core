<?hh

use Senary\Http\Request;

class RequestTest extends TestCase
{

    /**
     * Setup
     */
    public function setUp()
    {
        parent::setUp();
        $this->request = new Request('GET', '/foo/bar');
    }


    /**
     * @test
     */
    public function get_and_set_method()
    {
        $this->assertSame('GET', $this->request->getMethod());

        $this->request->setMethod('POST');
        $this->assertSame('POST', $this->request->getMethod());
    }


    /**
     * @test
     */
    public function get_and_set_method_alias()
    {
        $this->assertSame('GET', $this->request->method());

        $this->request->method('PUT');
        $this->assertSame('PUT', $this->request->getMethod());
    }


    /**
     * @test
     */
    public function set_method_normalizes_name()
    {
        $this->request->setMethod('delete');
        $this->assertSame('DELETE', $this->request->getMethod());
    }


    /**
     * @test
     */
    public function get_and_set_uri()
    {
        $this->assertSame('/foo/bar', $this->request->getUri());

        $this->request->setUri('/new');
        $this->assertSame('/new', $this->request->getUri());
    }


    /**
     * @test
     */
    public function get_and_set_uri_alias()
    {
        $this->assertSame('/foo/bar', $this->request->uri());

        $this->request->uri('/new');
        $this->assertSame('/new', $this->request->getUri());
    }


    /**
     * @test
     */
    public function get_and_set_query()
    {
        $this->assertEquals(Map{}, $this->request->getQuery());

        $this->request->setQuery(Map{'foo' => 'bar'});
        $this->assertEquals(Map{'foo' => 'bar'}, $this->request->getQuery());
    }


    /**
     * @test
     */
    public function get_and_set_query_alias()
    {
        $this->assertEquals(Map{}, $this->request->query());

        $this->request->query(Map{'foo' => 'bar'});
        $this->assertEquals(Map{'foo' => 'bar'}, $this->request->getQuery());
    }


    /**
     * @test
     */
    public function get_and_set_post()
    {
        $this->assertEquals(Map{}, $this->request->getPost());

        $this->request->setPost(Map{'foo' => 'bar'});
        $this->assertEquals(Map{'foo' => 'bar'}, $this->request->getPost());
    }


    /**
     * @test
     */
    public function get_and_set_post_alias()
    {
        $this->assertEquals(Map{}, $this->request->post());

        $this->request->post(Map{'foo' => 'bar'});
        $this->assertEquals(Map{'foo' => 'bar'}, $this->request->getPost());
    }


    /**
     * @test
     */
    public function get_and_set_server()
    {
        $this->assertEquals(Map{}, $this->request->getServer());

        $this->request->setServer(Map{'foo' => 'bar'});
        $this->assertEquals(Map{'foo' => 'bar'}, $this->request->getServer());
    }


    /**
     * @test
     */
    public function get_and_set_server_alias()
    {
        $this->assertEquals(Map{}, $this->request->server());

        $this->request->server(Map{'foo' => 'bar'});
        $this->assertEquals(Map{'foo' => 'bar'}, $this->request->getServer());
    }


}
