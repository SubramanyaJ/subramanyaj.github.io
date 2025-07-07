/* index.js */
document.addEventListener("DOMContentLoaded", function() {
	const darkModeToggle = document.getElementById("darkModeToggle");

	// Check for saved theme preference or default to dark mode
	if (localStorage.getItem('theme') === 'light-mode') {
		document.body.classList.remove('dark-mode');
		document.body.classList.add('light-mode');
		darkModeToggle.textContent = '🌙';
	}

	darkModeToggle.addEventListener("click", function() {
		if (document.body.classList.contains('dark-mode')) {
			document.body.classList.remove('dark-mode');
			document.body.classList.add('light-mode');
			darkModeToggle.textContent = '🌙';
			localStorage.setItem('theme', 'light-mode');
		} else {
			document.body.classList.remove('light-mode');
			document.body.classList.add('dark-mode');
			darkModeToggle.textContent = '☀️';
			localStorage.setItem('theme', 'dark-mode');
		}
	});
});
