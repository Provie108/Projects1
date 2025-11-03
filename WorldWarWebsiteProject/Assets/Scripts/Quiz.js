function generateQuiz(questions, quizContainer, resultsContainer, submitButton){

function showQuestions(questions, quizContainer){
	// we'll need a place to store the output and the answer choices
	var output = [];
	var answers;

	// for each question...
	for(var i=0; i<questions.length; i++){
		
		// first reset the list of answers
		answers = [];

		// for each available answer to this question...
		for(letter in questions[i].answers){

			// ...add an html radio button
			answers.push(
				'<label>'
					+ '<input type="radio" name="question'+i+'" value="'+letter+'">'
					+ letter + ': '
					+ questions[i].answers[letter]
				+ '</label>'
			);
		}

		// add this question and its answers to the output
		output.push(
			'<div class="question">' + questions[i].question + '</div>'
			+ '<div class="answers">' + answers.join('') + '</div>'
		);
	}

	// finally combine our output list into one string of html and put it on the page
	quizContainer.innerHTML = output.join('');
}

showQuestions(questions, quizContainer);

function showResults(questions, quizContainer, resultsContainer){
	
	// gather answer containers from our quiz
	var answerContainers = quizContainer.querySelectorAll('.answers');
	
	// keep track of user's answers
	var userAnswer = '';
	var numCorrect = 0;
	
	// for each question...
	for(var i=0; i<questions.length; i++){

		// find selected answer
		userAnswer = (answerContainers[i].querySelector('input[name=question'+i+']:checked')||{}).value;
		
		// if answer is correct
		if(userAnswer===questions[i].correctAnswer){
			// add to the number of correct answers
			numCorrect++;
			
			// color the answers green
			answerContainers[i].style.color = 'lightgreen';
		}
		// if answer is wrong or blank
		else{
			// color the answers red
			answerContainers[i].style.color = 'red';
		}
	}

	// show number of correct answers out of total
	resultsContainer.innerHTML = numCorrect + ' out of ' + questions.length;
}

submitButton.onclick = function(){
	showResults(questions, quizContainer, resultsContainer);
}

	
}


var myQuestions = [
	{
		question: "What were the main reasons for the first world war?",
		answers: {
			a: 'Murder of German President in Berlin',
			b: 'Murder of Austrias heir in Sarajevo',
			c: 'Territorial rivalry'
		},
		correctAnswer: 'b'
	},
	{
		question: "Which of the following was not a cause of WWI?",
		answers: {
			a: 'Nationalism',
			b: 'Franco-Prussian war',
			c: 'Hundred Year war'
		},
		correctAnswer: 'c'
	},
	{
		question: "Which country made the first declaration of war?",
		answers: {
			a: 'Serbia',
			b: 'Italy',
			c: 'Germany',
			d: 'Austria-Hungary'
		},
		correctAnswer: 'd'
	},
	{
		question: "Which German attack provoked Britain to go to war?",
		answers: {
			a: 'The Attack on Belgium',
			b: 'Attack on France',
			c: 'The Attack on Russia',
			d: 'The Attack on Luxembourg'
		},
		correctAnswer: 'a'
	},
	{
		question: "Which country joined the war on the side of the Allied Powers in 1916?",
		answers: {
			a: 'Greece',
			b: 'Ireland',
			c: 'Romania',
			d: 'USA'
		},
		correctAnswer: 'c'
	},
	{
		question: "World War I is also known as",
		answers: {
			a: 'The Kaisers war',
			b: 'The War of Veerdun',
			c: 'The War to End all Wars',
			d: 'The Joffres war'
		},
		correctAnswer: 'c'
	},
	{	question: "On which date did the United States declare war on Germany?",
		answers: {
			a: 'July3, 1914',
			b: 'April 6, 1917',
			c: 'November 4, 1917',
			d: 'TUSA did not declare war on Germany'
		},
		correctAnswer: 'b'
	},
	{	question: "On which date did the United States declare war on Germany?",
		answers: {
			a: 'July3, 1914',
			b: 'April 6, 1917',
			c: 'November 4, 1917',
			d: 'TUSA did not declare war on Germany'
		},
		correctAnswer: 'b'
		
	}
];

var quizContainer = document.getElementById('quiz');
var resultsContainer = document.getElementById('results');
var submitButton = document.getElementById('submit');

generateQuiz(myQuestions, quizContainer, resultsContainer, submitButton);