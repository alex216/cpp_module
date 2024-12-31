package main

const (
	Ps           = "> "
	Index_prompt = "index? "
)

type tests struct {
	name     string
	input    string
	expected string
}

func RetTestCase() []tests {

	return []tests{
		{
			name:     "launch",
			input:    "EXIT\n",
			expected: Ps,
		},
		{
			name:     "invalid cmd",
			input:    "hello\nEXIT\n",
			expected: Ps + Ps,
		},
		// add cmd
		{
			name: "add cmd",
			input: "" +
				"ADD\n" +
				"alex\n" +
				"eight\n" +
				"poo\n" +
				"12345678\n" +
				"I have a pen.\n" +
				"EXIT\n",
			expected: "" +
				Ps +
				"Enter first name: " +
				"Enter last name: " +
				"Enter nickname: " +
				"Enter phone number: " +
				"Enter darkest secret: " + Ps,
		},
		// search invalid index
		{
			name: "search invalid index",
			input: "" +
				"SEARCH\n" +
				"EXIT\n",
			expected: "" +
				Ps +
				"empty phonebook\n" +
				Ps,
		},
		// add one info with empty then search cmd
		{
			name: "add one info then search cmd",
			input: "" +
				"ADD\n" +
				"Christopher\n" +
				"\n" +
				"The Mind-Bender\n" +
				"12345678\n" +
				"I have a pen.\n" +
				"EXIT\n",
			expected: "" +
				Ps +
				"Enter first name: " +
				"Enter last name: " +
				"Enter nickname: " +
				"Enter phone number: " +
				"Enter darkest secret: " +
				"All fields are required\n" +
				Ps,
		},
		// add two info then search cmd, then index 1
		{
			name: "add two info then search cmd, then index 1",
			input: "" +
				"ADD\n" +
				"Xavier\n" +
				"Niel\n" +
				"fixer\n" +
				"42424242\n" +
				"I have a pen.\n" +
				"ADD\n" +
				"Christopher\n" +
				"Nolan\n" +
				"The mind-blower\n" +
				"012345678\n" +
				"piece of cake\n" +
				"SEARCH\n" +
				"42\n" +
				"SEARCH\n" +
				"424242424242424242\n" +
				"SEARCH\n" +
				"0.01\n" +
				"SEARCH\n" +
				"0a\n" +
				"SEARCH\n" +
				"-1\n" +
				"SEARCH\n" +
				"fourty-two\n" +
				"SEARCH\n" +
				"1\n" +
				"EXIT\n",
			expected: "" +
				Ps +
				"Enter first name: " +
				"Enter last name: " +
				"Enter nickname: " +
				"Enter phone number: " +
				"Enter darkest secret: " + Ps +
				"Enter first name: " +
				"Enter last name: " +
				"Enter nickname: " +
				"Enter phone number: " +
				"Enter darkest secret: " + Ps +
				"╭──────────╥──────────┬──────────┬──────────╮\n" +
				"│     index║first name│ last name│  nickname│\n" +
				"╞══════════╬══════════╪══════════╪══════════╡\n" +
				"│         0║    Xavier│      Niel│     fixer│\n" +
				"│         1║Christoph.│     Nolan│The mind-.│\n" +
				"╰──────────╨──────────┴──────────┴──────────╯\n" +
				Index_prompt +
				"Invalid index\n" +
				Ps +
				"╭──────────╥──────────┬──────────┬──────────╮\n" +
				"│     index║first name│ last name│  nickname│\n" +
				"╞══════════╬══════════╪══════════╪══════════╡\n" +
				"│         0║    Xavier│      Niel│     fixer│\n" +
				"│         1║Christoph.│     Nolan│The mind-.│\n" +
				"╰──────────╨──────────┴──────────┴──────────╯\n" +
				Index_prompt +
				"Invalid index\n" +
				Ps +
				"╭──────────╥──────────┬──────────┬──────────╮\n" +
				"│     index║first name│ last name│  nickname│\n" +
				"╞══════════╬══════════╪══════════╪══════════╡\n" +
				"│         0║    Xavier│      Niel│     fixer│\n" +
				"│         1║Christoph.│     Nolan│The mind-.│\n" +
				"╰──────────╨──────────┴──────────┴──────────╯\n" +
				Index_prompt +
				"Invalid index\n" +
				Ps +
				"╭──────────╥──────────┬──────────┬──────────╮\n" +
				"│     index║first name│ last name│  nickname│\n" +
				"╞══════════╬══════════╪══════════╪══════════╡\n" +
				"│         0║    Xavier│      Niel│     fixer│\n" +
				"│         1║Christoph.│     Nolan│The mind-.│\n" +
				"╰──────────╨──────────┴──────────┴──────────╯\n" +
				Index_prompt +
				"Invalid index\n" +
				Ps +
				"╭──────────╥──────────┬──────────┬──────────╮\n" +
				"│     index║first name│ last name│  nickname│\n" +
				"╞══════════╬══════════╪══════════╪══════════╡\n" +
				"│         0║    Xavier│      Niel│     fixer│\n" +
				"│         1║Christoph.│     Nolan│The mind-.│\n" +
				"╰──────────╨──────────┴──────────┴──────────╯\n" +
				Index_prompt +
				"Invalid index\n" +
				Ps +
				"╭──────────╥──────────┬──────────┬──────────╮\n" +
				"│     index║first name│ last name│  nickname│\n" +
				"╞══════════╬══════════╪══════════╪══════════╡\n" +
				"│         0║    Xavier│      Niel│     fixer│\n" +
				"│         1║Christoph.│     Nolan│The mind-.│\n" +
				"╰──────────╨──────────┴──────────┴──────────╯\n" +
				Index_prompt +
				"Invalid index\n" +
				Ps +
				"╭──────────╥──────────┬──────────┬──────────╮\n" +
				"│     index║first name│ last name│  nickname│\n" +
				"╞══════════╬══════════╪══════════╪══════════╡\n" +
				"│         0║    Xavier│      Niel│     fixer│\n" +
				"│         1║Christoph.│     Nolan│The mind-.│\n" +
				"╰──────────╨──────────┴──────────┴──────────╯\n" +
				Index_prompt +
				"First name:\tChristopher\n" +
				"Last name:\tNolan\n" +
				"Nickname:\tThe mind-blower\n" +
				"Phone number:\t012345678\n" +
				"Darkest secret:\tpiece of cake\n" +
				Ps,
		},
		// ADD 8 contacts, SEARCH, ADD one more, then SEARCH
		{
			name: "ADD 8 contacts, SEARCH, ADD one more, then SEARCH",
			input: "" +
				"ADD\nJohn\nDoe\nJD\n1111\nsecret1\n" +
				"ADD\nJane\nSmith\nJS\n2222\nsecret2\n" +
				"ADD\nBob\nJohnson\nBJ\n3333\nsecret3\n" +
				"ADD\nAlice\nWilliams\nAW\n4444\nsecret4\n" +
				"ADD\nCharlie\nBrown\nCB\n5555\nsecret5\n" +
				"ADD\nDianaLong\nMiller\nDM\n6666\nsecret6\n" +
				"ADD\nEricLonger\nDavis\nED\n7777\nsecret7\n" +
				"ADD\nFionaLongest\nGarcia\nFG\n8888\nsecret8\n" +
				"SEARCH\n" +
				"7\n" +
				"ADD\nGeorge\nWilson\nGW\n9999\nsecret9\n" +
				"SEARCH\n" +
				"0\n" +
				"EXIT\n",
			expected: "" +
				Ps + "Enter first name: Enter last name: Enter nickname: Enter phone number: Enter darkest secret: " +
				Ps + "Enter first name: Enter last name: Enter nickname: Enter phone number: Enter darkest secret: " +
				Ps + "Enter first name: Enter last name: Enter nickname: Enter phone number: Enter darkest secret: " +
				Ps + "Enter first name: Enter last name: Enter nickname: Enter phone number: Enter darkest secret: " +
				Ps + "Enter first name: Enter last name: Enter nickname: Enter phone number: Enter darkest secret: " +
				Ps + "Enter first name: Enter last name: Enter nickname: Enter phone number: Enter darkest secret: " +
				Ps + "Enter first name: Enter last name: Enter nickname: Enter phone number: Enter darkest secret: " +
				Ps + "Enter first name: Enter last name: Enter nickname: Enter phone number: Enter darkest secret: " +
				Ps +
				"╭──────────╥──────────┬──────────┬──────────╮\n" +
				"│     index║first name│ last name│  nickname│\n" +
				"╞══════════╬══════════╪══════════╪══════════╡\n" +
				"│         0║      John│       Doe│        JD│\n" +
				"│         1║      Jane│     Smith│        JS│\n" +
				"│         2║       Bob│   Johnson│        BJ│\n" +
				"│         3║     Alice│  Williams│        AW│\n" +
				"│         4║   Charlie│     Brown│        CB│\n" +
				"│         5║ DianaLong│    Miller│        DM│\n" +
				"│         6║EricLonger│     Davis│        ED│\n" +
				"│         7║FionaLong.│    Garcia│        FG│\n" +
				"╰──────────╨──────────┴──────────┴──────────╯\n" +
				Index_prompt +
				"First name:\tFionaLongest\n" +
				"Last name:\tGarcia\n" +
				"Nickname:\tFG\n" +
				"Phone number:\t8888\n" +
				"Darkest secret:\tsecret8\n" +
				Ps + "Enter first name: Enter last name: Enter nickname: Enter phone number: Enter darkest secret: " +
				Ps +
				"╭──────────╥──────────┬──────────┬──────────╮\n" +
				"│     index║first name│ last name│  nickname│\n" +
				"╞══════════╬══════════╪══════════╪══════════╡\n" +
				"│         0║    George│    Wilson│        GW│\n" +
				"│         1║      Jane│     Smith│        JS│\n" +
				"│         2║       Bob│   Johnson│        BJ│\n" +
				"│         3║     Alice│  Williams│        AW│\n" +
				"│         4║   Charlie│     Brown│        CB│\n" +
				"│         5║ DianaLong│    Miller│        DM│\n" +
				"│         6║EricLonger│     Davis│        ED│\n" +
				"│         7║FionaLong.│    Garcia│        FG│\n" +
				"╰──────────╨──────────┴──────────┴──────────╯\n" +
				Index_prompt +
				"First name:\tGeorge\n" +
				"Last name:\tWilson\n" +
				"Nickname:\tGW\n" +
				"Phone number:\t9999\n" +
				"Darkest secret:\tsecret9\n" +
				Ps,
			// bufferoverflow
			// empty test case input
		},
	}
}
