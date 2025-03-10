document.addEventListener("DOMContentLoaded", function() {
  // Check for saved language preference
  const translationsScript = document.getElementById('page-translations');
  
  if (translationsScript) {
    try {
      const translations = JSON.parse(translationsScript.textContent);
      
      const langToggleBtn = document.querySelector('.lang-toggle-btn');
      
      if (langToggleBtn) {
        langToggleBtn.addEventListener('click', function() {
          // Get the current page's language
          const currentLang = '{{ page.lang }}';
          
          // Find the translation for the other language
          const translation = translations.find(t => t.lang !== currentLang);
          
          if (translation) {
            // Navigate to the translated page
            window.location.href = translation.url;
          }
        });
      }
    } catch (error) {
      console.error('Error parsing translations:', error);
    }
  } else {
    console.error('Translations script not found');
  }
});