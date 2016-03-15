<?hh

class Log {
	// this array holds start times
	private array $timers = [];

	// this array holds start times
	// for globl timers
	private static array $globTimers = [];

	public function Println(string $s):void {
		echo date('H:i:s') . ' ' . $s . "\n";
		flush();
	}

	private function logStatus(string $s, string $status):void {
		$this->Println($s . ' ' . $status . '.');
	}

	public function Start(string $s):void {
		$this->logStatus($s, 'started');
	}

	public function StartT(string $s):void {
		$this->timers[$s] = time();

		$this->logStatus($s, 'started');
	}

	public function StartGlobalT(string $s):void {
		self::$globTimers[$s] = time();

		$this->logStatus($s, 'started');
	}

	public function Finish(string $s):void {
		$this->logStatus($s, 'finished');
	}

	public function FinishGlobalT(string $s):void {
		$finish = time();

		$this->logStatus($s, 'finished in ' . ($finish - self::$globTimers[$s]) . ' seconds.');
		unset(self::$globTimers[$s]);
	}

	public function FinishT(string $s):void {
		$finish = time();
		$this->logStatus($s, 'finished in ' . ($finish - $this->timers[$s]) . ' seconds.');
		unset($this->timers[$s]);
	}

	public function __invoke(string $s):void {
		$this->Println($s);
	}

	public function Value(mixed $v, ?string $name = null):void {
		$this->Println(
			($name ? $name . ': ' : null)
			. var_export($v, true)
		);
	}
}
