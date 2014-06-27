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
     * @var array
     */
    protected array<string, mixed> $query;


    /**
     * $_POST
     * @var array
     */
    protected array<string, mixed> $post;


    /**
     * $_SERVER
     * @var array
     */
    protected array<string, mixed> $server;


    /**
     * Constructor
     *
     * @param  string $method
     * @param  string $uri
     * @param  array  $query  - $_GET
     * @param  array  $post   - $_POST
     * @param  array  $server - $_SERVER
     * @return void
     */
    public function __construct
    (
        string $method,
        string $uri,
        array<string, mixed> $query=[],
        array<string, mixed> $post=[],
        array<string, mixed> $server=[]
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
     * @return array
     */
    public function getQuery() :array<string, mixed>
    {
        return $this->query;
    }


    /**
     * Set query ($_GET)
     *
     * @param  array $query
     * @return self
     */
    public function setQuery(array<string, mixed> $query) :this
    {
        $this->query = $query;
        return $this;
    }


    /**
     * Get and set query (_GET) alias
     *
     * @param  array $query
     * @return self|array
     */
    public function query(?array<string, mixed> $query = null) :mixed
    {
        if( is_null($query) ) return $this->query;

        return $this->setQuery($query);
    }


    /**
     * Get post (_POST)
     *
     * @return array
     */
    public function getPost() :array<string, mixed>
    {
        return $this->post;
    }


    /**
     * Set post (_POST)
     *
     * @param  array $post
     * @return self
     */
    public function setPost(array<string, mixed> $post) :this
    {
        $this->post = $post;
        return $this;
    }


    /**
     * Get and set post alias
     *
     * @param  array $post
     * @return self|array
     */
    public function post(?array<string, mixed> $post = null) :mixed
    {
        if( is_null($post) ) return $this->post;

        return $this->setPost($post);
    }


    /**
     * Get server (_SERVER)
     *
     * @return array
     */
    public function getServer() :array<string, mixed>
    {
        return $this->server;
    }


    /**
     * Set server (_SERVER)
     *
     * @param  array $server
     * @return self
     */
    public function setServer(array<string, mixed> $server) :this
    {
        $this->server = $server;
        return $this;
    }


    /**
     * Get and set server alias (_SERVER)
     *
     * @param  array $server
     * @return self|array
     */
    public function server(?array<string, mixed> $server = null) :mixed
    {
        if( is_null($server) ) return $this->server;

        return $this->setServer($server);
    }


}
