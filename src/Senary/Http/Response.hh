<?hh // strict
namespace Senary\Http;

class Response
{

    /**
     * Response content
     * @var string
     */
    protected string $content;


    /**
     * Response status
     * @var int
     */
    protected int $status;


    /**
     * Response headers
     * @var array
     */
    protected array<string, mixed> $headers;


    /**
     * Constructor
     *
     * @param  string $content
     * @param  int    $status
     * @param  array    $headers
     * @return void
     */
    public function __construct(string $content, int $status = 200, array<string, mixed> $headers = []) :void
    {
        $this->content = $content;
        $this->status = $status;
        $this->headers = $headers;
    }


    /**
     * Get content
     *
     * @return string
     */
    public function getContent() :string
    {
        return $this->content;
    }


    /**
     * Set content
     *
     * @param  string $content
     * @return self
     */
    public function setContent(string $content) :this
    {
        $this->content = $content;
        return $this;
    }


    /**
     * Get and set content alias
     *
     * @param  string $content
     * @return self|string
     */
    public function content(?string $content = null) :mixed
    {
        if( is_null($content) ) return $this->content;

        return $this->setContent($content);
    }


    /**
     * Get status
     *
     * @return int
     */
    public function getStatus() :int
    {
        return $this->status;
    }


    /**
     * Set status
     *
     * @param  int $status
     * @return self
     */
    public function setStatus(int $status) :this
    {
        $this->status = $status;
        return $this;
    }


    /**
     * Get and set status alias
     *
     * @param  int $status
     * @return self|int
     */
    public function status(?int $status = null) :mixed
    {
        if( is_null($status) ) return $this->status;

        return $this->setStatus($status);
    }


    /**
     * Get headers
     *
     * @return array
     */
    public function getHeaders() :array<string, mixed>
    {
        return $this->headers;
    }


    /**
     * Set headers
     *
     * @param  array $headers
     * @return self
     */
    public function setHeaders(array<string, mixed> $headers) :this
    {
        $this->headers = $headers;
        return $this;
    }


    /**
     * Get and set headers alias
     *
     * @param  array $headers
     * @return self|array
     */
    public function headers(?array<string, mixed> $headers = null) :mixed
    {
        if( is_null($headers) ) return $this->headers;

        return $this->setHeaders($headers);
    }

}
