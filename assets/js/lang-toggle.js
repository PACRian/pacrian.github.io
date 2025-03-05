document.addEventListener("DOMContentLoaded", function() {
  // Check for saved language preference
  const savedLang = localStorage.getItem('siteLanguage');
  
  // If no saved preference, detect browser language
  if (!savedLang) {
    const browserLang = navigator.language.substring(0, 2);
    // Only set to Chinese if browser explicitly requests it, otherwise default to English
    const initialLang = (browserLang === 'zh') ? 'zh' : 'en';
    setLanguage(initialLang);
  } else {
    setLanguage(savedLang);
  }
});
  
  function toggleLanguage() {
    const currentLang = document.documentElement.getAttribute('lang');
    const newLang = currentLang === 'en' ? 'zh' : 'en';
    setLanguage(newLang);
  }
  
  function setLanguage(lang) {
    // Update the HTML lang attribute for accessibility and SEO
    document.documentElement.setAttribute('lang', lang);
    
    // Store the user's language preference
    localStorage.setItem('siteLanguage', lang);
    
    // Update visible content
    document.querySelectorAll('[data-lang]').forEach(element => {
      if (element.classList.contains('lang-text')) {
        // For the toggle button text, show only the opposite language text
        element.style.display = element.getAttribute('data-lang') === lang ? 'none' : 'inline';
      } else {
        // For content elements, show only matching language
        element.style.display = element.getAttribute('data-lang') === lang ? 'block' : 'none';
      }
    });
    
    // Update page title if available in both languages
    const pageTitle = document.querySelector(`meta[data-lang="${lang}"][property="og:title"]`);
    if (pageTitle) {
      document.title = pageTitle.getAttribute('content');
    }
  }