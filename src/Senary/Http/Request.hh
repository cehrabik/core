<?hh // strict
namespace Senary\Http;

class Request
{

    /**
     * Method
     * @var string
     */
    protected string $method;


    /**
     * URI
     * @var string
     */
    protected string $uri;


    /**
     * $_GET
     * @var Map
     */
    protected Map<string, mixed> $query;


    /**
     * $_POST
     * @var Map
     */
    protected Map<string, mixed> $post;


    /**
     * $_SERVER
     * @var Map
     */
    protected Map<string, mixed> $server;


    /**
     * Constructor
     *
     * @param  string $method
     * @param  string $uri
     * @param  Map    $query  - $_GET
     * @param  Map    $post   - $_POST
     * @param  Map    $server - $_SERVER
     * @return void
     */
    public function __construct
    (
        string $method,
        string $uri,
        Map<string, mixed> $query=Map{},
        Map<string, mixed> $post=Map{},
        Map<string, mixed> $server=Map{}
    ) :void
    {
        $this->method = $method;
        $this->uri = $uri;
        $this->query = $query;
        $this->post = $post;
        $this->server = $server;
    }


    /**
     * Get method
     *
     * @return string
     */
    public function getMethod() :string
    {
        return $this->method;
    }


    /**
     * Set method
     *
     * @param  string $method
     * @return self
     */
    public function setMethod(string $method) :this
    {
        $this->method = $this->normalizeMethod($method);
        return $this;
    }


    /**
     * Normalize method
     *
     * @param  string $method
     * @return string
     */
    protected function normalizeMethod(string $method) :string
    {
        return strtoupper($method);
    }


    /**
     * Get and set method alias
     *
     * @param  string $method
     * @return self|string
     */
    public function method(?string $method = null) :mixed
    {
        if( is_null($method) ) return $this->method;

        return $this->setMethod($method);
    }


    /**
     * Get URI
     *
     * @return string
     */
    public function getUri() :string
    {
        return $this->uri;
    }


    /**
     * Set URI
     *
     * @param  string $uri
     * @return self
     */
    public function setUri(string $uri) :this
    {
        $this->uri = $uri;
        return $this;
    }


    /**
     * Get and set URI alias
     *
     * @param  string $uri
     * @return self|string
     */
    public function uri(?string $uri = null) :mixed
    {
        if( is_null($uri) ) return $this->uri;

        return $this->setUri($uri);
    }


    /**
     * Get query ($_GET)
     *
     * @return Map
     */
    public function getQuery() :Map<string, mixed>
    {
        return $this->query;
    }


    /**
     * Set query ($_GET)
     *
     * @param  Map $query
     * @return self
     */
    public function setQuery(Map<string, mixed> $query) :this
    {
        $this->query = $query;
        return $this;
    }


    /**
     * Get and set query (_GET) alias
     *
     * @param  Map $query
     * @return self|Map
     */
    public function query(?Map<string, mixed> $query = null) :mixed
    {
        if( is_null($query) ) return $this->query;

        return $this->setQuery($query);
    }


    /**
     * Get post (_POST)
     *
     * @return Map
     */
    public function getPost() :Map<string, mixed>
    {
        return $this->post;
    }


    /**
     * Set post (_POST)
     *
     * @param  Map $post
     * @return self
     */
    public function setPost(Map<string, mixed> $post) :this
    {
        $this->post = $post;
        return $this;
    }


    /**
     * Get and set post alias
     *
     * @param  Map $post
     * @return self|Map
     */
    public function post(?Map<string, mixed> $post = null) :mixed
    {
        if( is_null($post) ) return $this->post;

        return $this->setPost($post);
    }


    /**
     * Get server (_SERVER)
     *
     * @return Map
     */
    public function getServer() :Map<string, mixed>
    {
        return $this->server;
    }


    /**
     * Set server (_SERVER)
     *
     * @param  Map $server
     * @return self
     */
    public function setServer(Map<string, mixed> $server) :this
    {
        $this->server = $server;
        return $this;
    }


    /**
     * Get and set server alias (_SERVER)
     *
     * @param  Map $server
     * @return self|Map
     */
    public function server(?Map<string, mixed> $server = null) :mixed
    {
        if( is_null($server) ) return $this->server;

        return $this->setServer($server);
    }


}
